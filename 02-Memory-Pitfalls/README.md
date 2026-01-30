<img width="285" height="417" alt="image" src="https://github.com/user-attachments/assets/dad08b99-74e2-4514-993c-7ec1bfc80746" /># Memory Pitfalls

This project is a C++17 experimental laboratory designed to visualize and analyze common memory management errors. By utilizing a custom **Tracker** class, the project provides real-time insights into object lifetimes, stack-to-heap transitions, and the consequences of losing object ownership.

## Technical Design Decisions

### The Tracker Mechanism and Lifecycle Monitoring
To monitor the "birth" and "death" of objects, a dedicated `Tracker` class was implemented with the following features:
* **Static Counter for Global Tracking**: An `inline static` member variable acts as a global counter, assigning a unique ID to every instance created during the execution.
* **RAII-Based Reporting**: The constructor and destructor are leveraged to print status messages to the console. This allows for immediate visual confirmation of whether an object has been properly destroyed or leaked.
* **Const-Correct Status Checks**: A `check()` method is provided to verify if a memory address still points to a valid, "living" object.

[Image of C++ object lifetime and RAII visualization]

### MemoryLab: Simulating Critical Failures
The `MemoryLab` namespace contains template functions specifically designed to trigger and demonstrate four major memory pitfalls:
* **Stack Address Leakage (Dangling Pointers/References)**: Functions like `RetPtr_SegFault` return the address of a local variable. Since local variables are destroyed when they go out of scope, this demonstrates how "dangling" identifiers lead to Segmentation Faults or Undefined Behavior.
* **Unmanaged Heap Allocation**: `RetPtr_mustdel` allocates memory on the heap using `new` but returns a raw pointer. This forces the user to manually manage the memory, highlighting the risk of memory leaks if the pointer is lost or not deleted.
* **Semantic Ownership Errors**: `RetRef_mustdel` returns a reference to a heap-allocated object. This represents a severe design flaw where the caller may not even realize they own the memory, making a manual `delete` nearly impossible.

### Type Safety and Enum-Driven Experiments
To keep the testing environment organized, an `enum class Operations` was implemented:
* **Strong Typing**: Prevents accidental integer-to-enum conversions, ensuring that each experiment is explicitly called.
* **Centralized Dispatch**: Allows for a structured "Test Bench" where multiple memory experiments can be executed and stored in a pointer array for post-mortem analysis.

<img width="285" height="417" alt="image" src="https://github.com/user-attachments/assets/d96c5939-b43e-40ae-9fff-1c97986b7029" />



## Installation and Build

The project uses a standard CMake build system:
```bash
mkdir build && cd build
cmake ..
make
```
## Usage Example

The experiments can be triggered by calling the relevant `MemoryLab` function with the `Tracker` class as the template argument. By observing the console logs, you can monitor which objects are successfully destroyed and which ones persist as "memory leaks."

```cpp
#include "memorylab.hpp"
#include "tracker.hpp"
#include <iostream>

int main() {
    // 1. Simulating a Memory Leak (Heap allocation without delete)
    // Console will show [+] but never [-] because the object is lost in heap.
    Tracker* leakedObj = MemoryLab::retPtr_mustdel<Tracker>();
    leakedObj->check(); 

    // 2. Simulating a Dangling Pointer (Stack object address leakage)
    // Console will show [+] then [-] immediately as the function scope ends.
    Tracker* dangling = MemoryLab::retPtr_SegFault<Tracker>();
    
    // WARNING: Accessing a dangling pointer triggers Undefined Behavior.
    // dangling->check(); 

    return 0;
}
```
## Technical Insights and Blog

This project serves as a "pre-analysis" for Structural Design Patterns. It demonstrates why raw pointers are often insufficient for complex system designs and why abstractions like the **Proxy Pattern** or **Smart Pointers** are vital for memory safety in professional C++ development.

By tracking the `static` object counter, we can mathematically prove the existence of memory leaks that would otherwise remain hidden in large-scale embedded systems. For a detailed analysis of memory corruption, the difference between stack and heap lifetimes, and why modern C++ abstractions are necessary to solve these hurdles, please refer to the following article (Turkish):

**Medium:** [C++’ta Belleği Suçüstü Yakalamak: Nesne Yaşam Döngüleri ve Lab Analizi]

## Contact

**Uğur Altınışık** Electrical and Electronics Engineer | Embedded Software Engineer  
[LinkedIn Profile](https://www.linkedin.com/in/altnskuur/)
