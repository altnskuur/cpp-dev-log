# Performance Tracker

This project is a C++17 performance monitoring library based on the Pimpl (Pointer to Implementation) design pattern. The primary focus of the project is to minimize compile-time dependencies by establishing a "Compilation Firewall."

## Technical Design Decisions

### Pimpl Idiom and Compilation Optimization
The library isolates heavy system headers such as `<chrono>` and `<fstream>` from the public interface (`Tracer.hpp`). This design provides several key benefits:

- **Prevents Header Pollution:** Client code using this library does not need to include or process unnecessary system headers.
- **Accelerates Incremental Builds:** Changes made to the internal structure of the class (private members) do not trigger a recompilation of the client code. Only the library's own source file (`Tracer.cpp`) is recompiled.



### Memory Management and RAII
`std::unique_ptr` was chosen for the lifetime management of the `Impl` structure. The reasons for this choice are:
- **Memory Safety:** Automatically prevents memory leaks through the RAII (Resource Acquisition Is Initialization) principle.
- **Ownership:** Enforces clear ownership, preventing common errors associated with shallow copying of objects.
- **Incomplete Type Management:** By defining the destructor in the `.cpp` file, we successfully manage forward declaration constraints in the header file.

### Macro Design and Variable Naming
The `TRACE_SCOPE()` macro is designed to generate a unique local object for each invocation. The `__LINE__` macro undergoes a two-level expansion (double indirection) to produce line-number-sensitive variable names using token pasting (`##`). This architecture allows for multiple measurements within the same function block without identifier conflicts.



## Installation and Build

The project uses a standard CMake build system:

```bash
mkdir build && cd build
cmake ..
make
```


## Usage Example

Simply add the macro at the beginning of the scope you wish to measure. The object is created on the stack and reports the measurement results via its destructor when it goes out of scope.

```cpp
#include "Tracer.hpp"

void ExampleFunction() {
    TRACE_SCOPE();
    // Operations to be measured
}
```

## Technical Insights and Blog

For a detailed analysis of this project's architecture, its impact on C++ compilation processes, and the technical challenges encountered during development, please refer to the following article (Turkish):

[Medium: C++’ta Sınırları Belirlemek: Pimpl Idiom ve Derleme Duvarları](https://medium.com/@altnskuur/c-ta-s%C4%B1n%C4%B1rlar%C4%B1-belirlemek-pimpl-idiom-ile-derleme-duvarlar%C4%B1-%C3%B6rmek-6a15c4f9a268?postPublishedType=initial)

## Contact

**Uğur Altınışık** Electrical and Electronics Engineer | Embedded Software Engineer  
[LinkedIn Profile](https://www.linkedin.com/in/altnskuur)
