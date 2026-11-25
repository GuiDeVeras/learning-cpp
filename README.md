# C++ Study Plan for Big Tech (Competitive Programmer Track)

A hands-on roadmap for competitive programmers who want to move from "contest C++" to the C++ and engineering practices Big Tech companies expect in interviews and on the job.

**Prerequisite:** you can already write contest-style C++ (`vector`, `string`, basic classes, basic pointers and references). There is no "Phase 0" in this plan. If pointers or references feel shaky, spend 2-3 days on *A Tour of C++* (first chapters) before Week 1.

> **Note:** Video titles and speakers were listed from memory. If a title does not match exactly, search by speaker name and event (CppCon, C++Now, etc.). Durations and Style Guide section names are approximate; check them against the current versions.

---

## Table of Contents

1. [Goal and Mindset](#1-goal-and-mindset)
2. [Company Types and What They Test](#2-company-types-and-what-they-test)
3. [How This Plan Works](#3-how-this-plan-works)
4. [Study Layers](#4-study-layers)
5. [Timeline](#5-timeline)
6. [Week 1 Tooling Setup (CMake, GoogleTest, Sanitizers)](#6-week-1-tooling-setup-cmake-googletest-sanitizers)
7. [Session Plan: Layer A (Weeks 1-3)](#7-session-plan-layer-a-weeks-1-3)
8. [Session Plan: Layers B, C, D (Weeks 4-10)](#8-session-plan-layers-b-c-d-weeks-4-10)
9. [Google C++ Style Guide Reading Plan](#9-google-c-style-guide-reading-plan)
10. [Layers E (Advanced) and F, Projects, Interviews (Weeks 11-18)](#10-layers-e-advanced-and-f-projects-interviews-weeks-11-18)
11. [Essentials Only (Minimum Viable List)](#11-essentials-only-minimum-viable-list)
12. [Hours Estimate](#12-hours-estimate)
13. [Portfolio Projects](#13-portfolio-projects)
14. [Books and Other Resources](#14-books-and-other-resources)
15. [Layer A Glossary](#15-layer-a-glossary)
16. [Tips](#16-tips)

---

## 1. Goal and Mindset

Contest programmers already have the hardest part: algorithms and implementation speed. What is usually missing:

1. **Production-style C++**, not contest C++ (no `#define int long long`, no `bits/stdc++.h`)
2. **Engineering habits:** tests, sanitizers, build systems, readable code
3. **System design**
4. **Communication and behavioral interviews**
5. **Low-level knowledge**, depending on the role

---

## 2. Company Types and What They Test

| Company type | Examples | Focus |
|---|---|---|
| General Big Tech | Google, Meta, Amazon, Microsoft, Apple | Algorithms + system design + behavioral. C++ is often optional in the interview |
| C++-heavy Big Tech | Nvidia, Microsoft (Windows/Azure core), Google (Chrome, infra), Meta (infra), Apple (systems) | All of the above + modern C++, memory, concurrency |
| Trading / Quant | Citadel, Jump, Optiver, IMC, HRT, Jane Street | Probability, puzzles, low-latency C++, optimization |
| Systems, games, embedded | Epic, Unity, Tesla, Qualcomm | Deep C++, computer architecture, concurrency |

The closer to trading and systems, the deeper the C++ questions go.

---

## 3. How This Plan Works

### The learning loop (active, not passive)

Never spend a whole week only watching talks. Every study session follows this loop:

1. **Read (10-15 min):** one section of the Google C++ Style Guide or a few cppreference pages.
2. **Watch (15-25 min):** one *segment* of a talk. Dense talks (Sutter, Meyers, Carruth, Godbolt, *atomic<> Weapons*) are **never** watched in one sitting; split them into 20-25 min chunks.
3. **Code immediately (45-60 min):** reproduce the examples, then apply the idea to the layer's exercise.
4. **Verify (10 min):** run your unit tests and the sanitizers.
5. **Note (3 lines):** what you learned, what broke, what you still do not understand.

**Rule of thumb:** no more than ~30 minutes of video before you write code.

### Definition of done (for every exercise from Week 1 on)

An exercise is finished only when:

- [ ] It builds with `-Wall -Wextra -Wpedantic` and no warnings
- [ ] It has GoogleTest unit tests, including edge cases
- [ ] Tests pass under **ASan + UBSan** (leaks, use-after-free, overflow, UB)
- [ ] Concurrency code also passes under **TSan**
- [ ] You applied at least one Style Guide rule you learned that session

---

## 4. Study Layers

### Layer A: Modern C++ (C++11 to C++23)
- **Resource management:** RAII, `unique_ptr`, `shared_ptr`, `weak_ptr`
- **Move semantics:** rvalue references, `std::move`, `std::forward`, Rule of 0/3/5
- **Templates:** deduction, SFINAE, concepts (C++20), variadic templates, `constexpr`/`consteval`
- **Everyday tools:** lambdas, `auto`, structured bindings, `std::optional`, `std::variant`, `std::string_view`, `std::span`
- **Ranges and views (C++20)**, `std::format`
- **Polymorphism:** virtual, vtable, when to avoid it, CRTP
- **Undefined behavior:** aliasing, lifetime, iterator invalidation, ODR

**In one sentence:** describe resource ownership through types, move instead of copy when it makes sense, and avoid UB by knowing the pitfalls.

### Layer E1: Core Tooling (now part of Week 1)
- CMake basics (targets, `FetchContent`, build types)
- GoogleTest basics (`TEST`, `EXPECT_*`/`ASSERT_*`, fixtures)
- Sanitizers: ASan, UBSan, TSan
- Warning flags, `clang-format`

### Layer B: The STL Under the Hood
- Complexity and real implementation of `vector`, `unordered_map`, `map`, `deque`, `list`
- Allocators, small string optimization
- Cache cost: why `vector` almost always beats `list`
- Writing your own simple containers

### Layer C: Low Level and Performance
- Memory model: stack, heap, alignment, struct layout, padding
- Cache, locality, false sharing, branch prediction
- Profiling: `perf`, `valgrind`, Google Benchmark, Compiler Explorer

### Layer D: Concurrency
- `std::thread`, `mutex`, `condition_variable`, `atomic`, memory orders
- `std::async`/`future`, thread pools
- Basic lock-free, producer/consumer
- Deadlock, race conditions, ABA problem

### Layer E2: Advanced Engineering (later)
- Advanced CMake (packages, install, multiple targets), CI basics
- GDB/LLDB, advanced Git
- Linux, OS fundamentals, networking (TCP, sockets)

### Layer F: Interview Skills
- **Algorithms:** practice explaining out loud, discussing trade-offs, writing clean readable code
- **System design:** scalability, databases, caching, queues, consistency, sharding
- **Behavioral:** stories in STAR format

---

## 5. Timeline

| Weeks | Focus | Deliverable (with tests + sanitizers) |
|---|---|---|
| 1-3 | **Layer A + tooling (E1)** | CMake project, RAII wrapper, `unique_ptr`, `vector<T>`, all tested under ASan/UBSan |
| 4-5 | Layer B | Hash table + benchmark comparing containers |
| 6-7 | Layer C | Optimized program with documented benchmark gains |
| 8-10 | Layer D | Thread pool + concurrent queue, clean under TSan |
| 11-14 | Portfolio project, Layer E2, system design | Finished project, 4-6 system designs |
| 15-18 | Mock interviews, applications | |

About **4 months** at 12-13 hours per week. Layers E2 and F can run in parallel earlier (1 short video per week).

---

## 6. Week 1 Tooling Setup (CMake, GoogleTest, Sanitizers)

Since your first exercises (`unique_ptr`, `vector`) should be validated by real tests and leak detectors, tooling comes first.

> **Windows users:** use WSL2 (Ubuntu) so GCC/Clang sanitizers work. Native MSVC supports ASan but not the same UBSan/TSan setup.

### Suggested layout

```
cpp-prep/
├── CMakeLists.txt
├── include/
│   └── my_unique_ptr.h
└── tests/
    └── unique_ptr_test.cpp
```

### `CMakeLists.txt`

```cmake
cmake_minimum_required(VERSION 3.20)
project(cpp_prep LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options(-Wall -Wextra -Wpedantic)

# Choose sanitizers at configure time:
#   -DSANITIZE=address,undefined   (memory errors + UB)
#   -DSANITIZE=thread              (data races; cannot be combined with ASan)
set(SANITIZE "" CACHE STRING "Sanitizers to enable")
if(SANITIZE)
  add_compile_options(-fsanitize=${SANITIZE} -fno-omit-frame-pointer -g)
  add_link_options(-fsanitize=${SANITIZE})
endif()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()
include(GoogleTest)

add_executable(unique_ptr_test tests/unique_ptr_test.cpp)
target_include_directories(unique_ptr_test PRIVATE include)
target_link_libraries(unique_ptr_test PRIVATE GTest::gtest_main)
gtest_discover_tests(unique_ptr_test)
```

### Build and run

```bash
# Normal build
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure

# ASan + UBSan build
cmake -S . -B build-asan -DSANITIZE=address,undefined
cmake --build build-asan
ctest --test-dir build-asan --output-on-failure

# TSan build (for concurrency, Weeks 8-10)
cmake -S . -B build-tsan -DSANITIZE=thread
cmake --build build-tsan
ctest --test-dir build-tsan --output-on-failure
```

### First test (`tests/unique_ptr_test.cpp`)

```cpp
#include <gtest/gtest.h>

#include <utility>

#include "my_unique_ptr.h"

TEST(UniquePtr, MoveTransfersOwnership) {
  my::unique_ptr<int> a(new int(42));
  my::unique_ptr<int> b = std::move(a);

  EXPECT_EQ(a.get(), nullptr);
  ASSERT_NE(b.get(), nullptr);
  EXPECT_EQ(*b, 42);
}

TEST(UniquePtr, ResetReleasesOldObject) {
  my::unique_ptr<int> p(new int(1));
  p.reset(new int(2));
  EXPECT_EQ(*p, 2);
}
```

### "Break it on purpose" exercises

Do these once so you learn what each sanitizer's report looks like:

- [ ] Remove the `delete` from your destructor, then run under ASan. **LeakSanitizer** reports the leak.
- [ ] Add a second `delete` of the same pointer. ASan reports **double-free**.
- [ ] Read an element of your `vector` after a `push_back` reallocation. ASan reports **heap-use-after-free**.
- [ ] Overflow a signed `int` in a test. UBSan reports **signed integer overflow**.

### Setup reading (short)

- [ ] Official **CMake Tutorial** (cmake.org), first steps only
- [ ] **GoogleTest Primer** (google.github.io/googletest)
- [ ] **AddressSanitizer** and **ThreadSanitizer** pages on the Google Sanitizers wiki (github.com/google/sanitizers)

---

## 7. Session Plan: Layer A (Weeks 1-3)

Each session is ~1.5-2 hours following the learning loop. Three sessions per week is the baseline.

### Week 1: Tooling + ownership

**Session 1: Tooling setup**
- [ ] Read: CMake Tutorial, GoogleTest Primer (see above)
- [ ] Code: build the project from Section 6, write the first test, run ASan/UBSan
- [ ] Do the "break it on purpose" exercises

**Session 2: RAII**
- [ ] Style Guide: *Ownership and Smart Pointers*
- [ ] Watch: **CppCon, Back to Basics: RAII** (in 1-2 segments)
- [ ] Code: an RAII wrapper around `FILE*` (opens in constructor, closes in destructor) + tests, including an early return and a thrown exception

**Session 3: Smart pointers**
- [ ] Style Guide: *Copyable and Movable Types*
- [ ] Watch: **CppCon, Back to Basics: Smart Pointers**
- [ ] Code: replace every raw `new`/`delete` in an old contest solution with `unique_ptr`; start your own `my::unique_ptr<T>` (constructor, destructor, `get`, `operator*`, `operator->`)

### Week 2: Move semantics + Rules of 0/3/5

**Session 4: lvalue, rvalue, move**
- [ ] Style Guide: *Rvalue References*
- [ ] Watch: **Klaus Iglberger, Back to Basics: Move Semantics** (segment 1: lvalue/rvalue; segment 2: move constructor/assignment)
- [ ] Code: finish `my::unique_ptr` with move constructor, move assignment, `release`, `reset`, `swap`; delete the copy operations; full test suite under ASan/UBSan

**Session 5: Rule of 0/3/5**
- [ ] Style Guide: *Structs vs. Classes*, *Doing Work in Constructors*
- [ ] Watch: **CppCon, Back to Basics: Rule of Zero / Three / Five**
- [ ] Code: a `Buffer` class that owns a heap array. Write it first with the Rule of 5, then rewrite it with `std::vector` (Rule of 0). Test with a "counter" type that logs copies and moves

**Session 6: Start `vector<T>`**
- [ ] Style Guide: *Inputs and Outputs*
- [ ] Watch: one short **C++ Weekly (Jason Turner)** episode on move or `emplace_back`
- [ ] Code: `my::vector<T>` with `push_back`, `size`, `capacity`, `operator[]`, geometric growth; tests for growth and reallocation under ASan

### Week 3: Modern toolbox + finish `vector`

**Session 7: Everyday modern C++**
- [ ] Style Guide: *Type Deduction* (`auto`), *Lambda Expressions*
- [ ] Watch: **C++ Weekly** episodes on `auto`, `optional`, `string_view` (5-10 min each, 2-3 of them)
- [ ] Code: refactor 3 of your own contest solutions into production style (clear names, `const`, no macros, `optional` instead of sentinel values like `-1`)

**Session 8: Templates + finish `vector`**
- [ ] Style Guide: *Template Metaprogramming*, *Concepts and Constraints*
- [ ] Watch: **CppCon, Back to Basics: Lambdas and Templates** (segment)
- [ ] Code: make `my::vector<T>` fully generic: copy/move constructors, `emplace_back`, `reserve`, iterators; tests for **iterator invalidation**, non-trivial `T`, and exception safety

**Session 9: Consolidation (heavy talks, in small pieces)**
- [ ] Watch in 2-3 chunks, coding after each: **Herb Sutter, Back to the Basics! Essentials of Modern C++ Style** (CppCon 2014)
- [ ] Watch: **Scott Meyers, Universal References in C++11** (last; the most advanced)
- [ ] Review: answer the [Layer A mastery check](#layer-a-mastery-check) without looking anything up

> The Sutter talk assumes you know "old" C++ (`new`/`delete`, raw pointers). By Session 9 most of its vocabulary will already be familiar. See the [glossary](#15-layer-a-glossary) if not.

---

## 8. Session Plan: Layers B, C, D (Weeks 4-10)

Same loop, same Definition of Done.

### Layer B: STL under the hood (Weeks 4-5)

- [ ] **S1:** Watch **Chandler Carruth, Efficiency with Algorithms, Performance with Data Structures** (CppCon 2014), first half → *Code:* benchmark `vector` vs `list` vs `deque` vs `map` on inserts and traversal (Quick Bench or Google Benchmark)
- [ ] **S2:** Second half of the Carruth talk → *Code:* write down, from your own results, why `vector` wins most of the time
- [ ] **S3:** Watch **Stephan T. Lavavej, STL Features and Implementation Techniques** (segments) → *Code:* read the `push_back` growth logic in libstdc++ or libc++ and compare with your `my::vector`
- [ ] **S4:** Watch **Matt Kulukundis, Designing a Fast, Efficient, Cache-friendly Hash Table** (Swiss Tables, CppCon 2017) in segments → *Code:* open-addressing hash table, tests under ASan/UBSan
- [ ] **S5:** *Code:* benchmark your hash table against `std::unordered_map`
- [ ] Style Guide this layer: *Integer Types*, *Use of const*, *Use of constexpr*

**Deliverable:** `my::vector`, a simple hash table, and a short benchmark report.

### Layer C: Low level and performance (Weeks 6-7)

- [ ] **S1:** Watch **Matt Godbolt, What Has My Compiler Done for Me Lately?** in segments, with godbolt.org open → *Code:* compare `-O0` vs `-O2` assembly for small functions
- [ ] **S2:** Watch **Timur Doumler, Want fast C++? Know your hardware!** → *Code:* experiment with sorted vs unsorted data (branch prediction) and struct padding (`sizeof`/`alignof`)
- [ ] **S3:** Watch **Mike Acton, Data-Oriented Design and C++** (CppCon 2014) → *Code:* AoS vs SoA benchmark
- [ ] **S4:** Watch **Chandler Carruth, Tuning C++: Benchmarks, and CPUs, and Compilers! Oh My!** → *Code:* profile one of your programs with `perf` and fix the top hotspot
- [ ] Style Guide this layer: *Preprocessor Macros*, *Casting*, *Architecture Portability*
- [ ] *Going further:* CMU 15-213 (CS:APP) lectures on cache and memory; MIT 6.172 Performance Engineering

**Deliverable:** optimized program with before/after benchmarks and a written explanation.

### Layer D: Concurrency (Weeks 8-10)

- [ ] **S1:** Watch **Anthony Williams, an introductory C++ concurrency talk** (CppCon or ACCU) → *Code:* `std::thread` + `std::mutex` counter; reproduce a data race, catch it with **TSan**, fix it
- [ ] **S2:** Watch **Herb Sutter, *atomic<> Weapons*, part 1** in 2 segments → *Code:* `std::atomic` flag/counter experiments with different memory orders
- [ ] **S3:** **Part 2** in 2 segments → *Code:* spinlock using `atomic`, tested under TSan
- [ ] **S4:** Watch **Fedor Pikus, a talk on lock-free programming or the cost of synchronization** → *Code:* single-producer single-consumer queue
- [ ] **S5-S6:** *Code:* thread pool with a concurrent task queue (`condition_variable`), full tests, TSan clean
- [ ] Reading this layer: **C++ Core Guidelines, section CP (Concurrency)**
- [ ] *Bonus:* Jon Gjengset, *Crust of Rust: Atomics and Memory Ordering* (Rust, but the concepts are the same)

**Deliverable:** thread pool + concurrent queue, clean under TSan.

---

## 9. Google C++ Style Guide Reading Plan

The guide lives at **google.github.io/styleguide/cppguide.html**. Read one short section per session (10-15 min), then **find one violation in your own code and fix it**. Section names are approximate; look for the closest heading.

| Week | Sections to read | Why it matters |
|---|---|---|
| 1 | *Ownership and Smart Pointers*, *Copyable and Movable Types* | Who owns what; when types should be copyable |
| 2 | *Rvalue References*, *Structs vs. Classes*, *Doing Work in Constructors*, *Inputs and Outputs* | Move semantics in practice; parameter passing conventions |
| 3 | *Type Deduction*, *Lambda Expressions*, *Template Metaprogramming*, *Concepts and Constraints* | Where `auto`, lambdas and templates help and where they hurt readability |
| 3 | *Naming*, *Comments*, *Formatting* | What readable production code looks like; set up `clang-format` |
| 4-5 | *Integer Types*, *Use of const*, *Use of constexpr* | Signed vs unsigned pitfalls, immutability |
| 6-7 | *Preprocessor Macros*, *Casting*, *Architecture Portability* | Why macros and C-style casts are discouraged |
| 8-10 | C++ Core Guidelines, section CP (Concurrency) | Rules for threads and locks |

**Read critically.** The Google guide is one company's set of rules, not the language standard. For example, it restricts exceptions for historical reasons that do not apply everywhere. Learn the *reasons* behind each rule so you can discuss trade-offs in interviews.

---

## 10. Layers E (Advanced) and F, Projects, Interviews (Weeks 11-18)

### Weeks 11-14: project, E2 and system design (in parallel)

**Portfolio project (see Section 13):** ~8 hours per week, with tests, sanitizers and a CMake build. Treat it like a small production codebase.

**Layer E2 (1-2 short sessions per week):**
- [ ] **Daniel Pfeifer, Effective CMake** (C++Now 2017), in segments, applying it to your project
- [ ] **MIT Missing Semester:** shell, Git, debugging lectures
- [ ] Set up **CI** (e.g., GitHub Actions) running your tests under ASan/UBSan/TSan
- [ ] Learn **GDB/LLDB** basics by debugging one deliberate bug

**Layer F: System design (from Week 4, 1 video per week; intensive here):**
- [ ] **ByteByteGo:** system design fundamentals playlist
- [ ] **Gaurav Sen:** 3-4 classic cases (URL shortener, chat, rate limiter)
- [ ] **Hussein Nasser:** 1-2 videos on databases and indexes
- [ ] **Hello Interview:** commented mock interviews to see the real format
- [ ] *Going further:* CMU 15-445 Database Systems (Andy Pavlo), MIT 6.824/6.5840 Distributed Systems
- [ ] *Exercise:* do 4-6 system designs on paper, out loud, with a timer

### Weeks 15-18: interviews

- Mock interviews (Pramp, interviewing.io, friends) at least once a week
- Behavioral stories in STAR format
- Keep 3-4 algorithm problems per week, explained out loud
- Update your resume: medals, rankings (ICPC, Codeforces, national contests), projects
- Start applying

### Trading / low latency (optional, only if it is your target)

- [ ] **Carl Cook, When a Microsecond Is an Eternity** (CppCon 2017)
- [ ] **David Gross, Trading at Light Speed** (Meeting C++ 2022)

---

## 11. Essentials Only (Minimum Viable List)

If you have very little time, do **Week 1 tooling** plus these 6 talks, each followed by code:

1. **Herb Sutter, Essentials of Modern C++ Style** (A)
2. **Klaus Iglberger, Back to Basics: Move Semantics** (A)
3. **Chandler Carruth, Efficiency with Algorithms, Performance with Data Structures** (B)
4. **Matt Godbolt, What Has My Compiler Done for Me Lately?** (C)
5. **Herb Sutter, atomic<> Weapons** (D)
6. **ByteByteGo, system design playlist** (F)

With the 4 main exercises (tested `unique_ptr`, `vector`/hash table, benchmark, thread pool) this takes roughly 60-80 hours. It is enough for general C++ roles, but not for systems or trading roles.

---

## 12. Hours Estimate

Approximate. Exact video lengths were not checked. Phase 0 is removed (about 25-30 hours saved), but tooling, tests and style reading add some back.

| Item | Hours |
|---|---|
| Videos (~40h of video) with pauses and segments | ~60-85h |
| Coding sessions and exercises with tests and sanitizers (`unique_ptr`, `vector`, hash table, benchmark, thread pool) | ~45-55h |
| Tooling setup + Style Guide reading | ~12-16h |
| Portfolio project | ~30-50h |
| Ongoing algorithm practice and mock interviews | ~30-40h |
| **Realistic total** | **~180-250h** |

### Calendar

| Hours per week | Approximate duration |
|---|---|
| 8h | ~5-7 months |
| 12h | ~3.5-5 months |
| 15h | ~3-4 months |
| 20h | ~2-3 months |

### Ways to reduce it
- **Minimum version:** Week 1 tooling + the 6 essential talks + the 4 main exercises (~60-80h).
- **Skip Layer F at first** if the initial focus is C++, and return to it 1-2 months before applying.
- **Skip the portfolio project** only if you have strong existing projects or contest results to show.

---

## 13. Portfolio Projects

Pick 1 or 2. Each must have CMake, unit tests, sanitizer runs and a short README.

- **Multithreaded TCP/HTTP server** with a thread pool
- **In-memory key-value store** with persistence (simplified Redis)
- **Custom memory allocator** with benchmarks
- **Order book matching engine** (great for trading roles)
- **Mini search engine or compressor** (Huffman/LZ)

---

## 14. Books and Other Resources

### Books
- *A Tour of C++* (Stroustrup): fast, modern overview
- *Effective Modern C++* (Scott Meyers): the classic for C++11/14
- *C++ Concurrency in Action* (Anthony Williams)
- *C++ Templates: The Complete Guide* (Vandevoorde): reference and deep dive
- *Designing Data-Intensive Applications* (Kleppmann): essential for system design
- *Computer Systems: A Programmer's Perspective* (CS:APP): low level

### Online
- Google C++ Style Guide: google.github.io/styleguide/cppguide.html
- C++ Core Guidelines: isocpp.github.io/CppCoreGuidelines
- GoogleTest docs: google.github.io/googletest
- CMake Tutorial: cmake.org/cmake/help/latest/guide/tutorial
- Google Sanitizers wiki: github.com/google/sanitizers
- [cppreference.com](https://cppreference.com): mandatory reference
- [Compiler Explorer](https://godbolt.org) and [Quick Bench](https://quick-bench.com)
- CppCon and C++Now channels on YouTube
- System Design Primer (GitHub) and ByteByteGo

---

## 15. Layer A Glossary

Terms that tend to block beginners, especially in the Herb Sutter talk.

### Ownership and memory
- **Ownership:** who is responsible for releasing a resource. In modern C++ the type tells you (`unique_ptr` = single owner).
- **Raw pointer:** the traditional `T*`. In the modern view it means "I observe, but I do not own".
- **Stack vs heap:** the stack is automatic and fast (local variables). The heap is allocated manually (`new`) and must be released.
- **Dangling pointer:** a pointer to something already destroyed.
- **Memory leak:** allocated memory that is never released.

### Values and moves
- **lvalue:** something with a name and an address, like variable `x`.
- **rvalue:** a temporary value without a name, like `x + 1` or a function's return value.
- **Move:** transferring an object's contents instead of copying them.
- **Sink parameter:** a function parameter whose value the function keeps. Usually taken by value and then `std::move`d.

### Parameter passing
- **By value, by reference, by `const` reference:** `f(T x)`, `f(T& x)`, `f(const T& x)`.
- **in / out / in-out:** Herb's classification of a parameter's role.
- **Return by value:** cheap today thanks to move and RVO.
- **RVO / copy elision:** the compiler constructs the object directly at the destination, skipping the copy.

### Modern syntax
- **`auto`**, **range-for** (`for (auto& x : v)`), **uniform initialization** (`std::vector<int> v{1, 2, 3};`), **`nullptr`**
- **`override` / `final`:** mark virtual functions so the compiler checks them
- **`= default` / `= delete`:** request or forbid the default version of a function
- **`const` correctness:** mark `const` everything that should not change

### Smart pointers
- **`make_unique` / `make_shared`:** the recommended way to create smart pointers instead of `new`
- **Reference counting:** counter of how many `shared_ptr`s point to the same object
- **Cyclic reference:** two `shared_ptr`s pointing at each other, never freed; `weak_ptr` solves it

### Layer A mastery check

Can you answer these without looking anything up?
1. Why can a `unique_ptr` not be copied but can be moved?
2. What happens to `a` after `std::move(a)`?
3. When should you use `shared_ptr` instead of `unique_ptr`?
4. Why can `push_back` invalidate iterators?
5. What is the Rule of Zero and why is it preferred?

---

## 16. Tips

1. **Code every session.** Never go a week only watching talks. Watching alone does not stick.
2. **Test everything.** If a data structure has no tests and no sanitizer run, it is not finished.
3. **Change your coding style.** In interviews, clear names and readable code beat macros and shortcuts.
4. **Ask which language is allowed.** Many Big Techs allow C++, which is an advantage for you.
5. **Show C++ depth when it comes up naturally.** Mentioning amortized complexity, iterator invalidation, or choosing a container for cache behavior makes an impression.
6. **Practice mock interviews.** Contest programmers usually lose points on communication, not on the algorithm.
7. **Read real code.** Spend about an hour a week in the STL, Abseil or Folly.
8. **College is not enough.** Many courses teach "C with classes" C++ and rarely cover RAII, move semantics, concurrency, performance or system design in depth.
