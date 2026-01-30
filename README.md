# cpp-dev-log

A specialized C++ Engineering Log documenting technical hurdles, memory management experiments, and structural design challenges encountered during the development of embedded and high-performance systems.

## Project Overview
This repository serves as a personal laboratory and a "Dev Log" for exploring the deeper mechanics of Modern C++. Instead of just implementing design patterns, this project focuses on the **"Why"** behind them—analyzing memory pitfalls, compilation bottlenecks, and architectural trade-offs.

## Repository Structure

The log is organized into specialized modules, each targeting a specific engineering hurdle:

### [01-Performance-Tracking](./01-Performance-Tracking)
Focuses on measuring execution time while maintaining a clean public interface.
* **Key Topics:** Pimpl Idiom, RAII, Scoped Measurements, Compilation Firewalls.
* **Goal:** How to monitor system performance without polluting client code with system headers like `<chrono>`.

### [02-Memory-Pitfalls](./02-Memory-Pitfalls)
A deep dive into object lifetimes and the dangers of manual memory management.
* **Key Topics:** Stack vs Heap Lifetimes, Dangling Pointers, Memory Leaks, Static Lifecycle Tracking.
* **Goal:** Visualizing common memory errors using a custom `Tracker` mechanism to justify the need for smarter abstractions.

## Tech Stack & Tools
* **Language:** Modern C++ (C++17 and beyond)
* **Build System:** CMake (Version 3.10+)
* **Compiler:** Tested with GCC/MinGW
* **Principles:** RAII, Pimpl, Strong Typing, Clean Code

## Engineering Philosophy
This repository is built on the principle that **understanding the failure is the first step to a robust design.** Each experiment documented here started with a "CS hurdle"—a specific point of confusion or a common pitfall—and evolved into a documented engineering solution.

## Blog Series
Each module in this repository is accompanied by a detailed technical article. You can find the deep-dive analyses on my Medium profile.

## License
This project is licensed under the **MIT License** - see the [LICENSE](LICENSE) file for details.

---
**Uğur Altınışık** *Electrical and Electronics Engineer | Embedded Software Engineer* [LinkedIn Profile](https://www.linkedin.com/in/uguraltinisik/)
