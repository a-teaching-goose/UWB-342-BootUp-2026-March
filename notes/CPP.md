<img width="40%" height="1024" alt="image" src="https://github.com/user-attachments/assets/1c3a1745-3386-461b-bc1e-1a8f60843c94" />

# C++

## Session recording
[Video](TBD) - Will be added after lecture.

---

## Tooling: Compilers & IDEs

### Compilers on Different Platforms
- **Windows**
  - [MinGW-w64](http://mingw-w64.org/) → `g++` for Windows.
  - [Microsoft Visual C++ (MSVC)](https://visualstudio.microsoft.com/) → integrated with Visual Studio.
- **macOS**
  - Apple’s `clang++` comes with Xcode Command Line Tools (`xcode-select --install`).
  - `g++` available via [Homebrew](https://brew.sh/).
- **Linux**
  - `g++` (GNU Compiler Collection) is standard on most distros (`sudo apt install g++`).
  - `clang++` often available as an alternative (`sudo apt install clang`).

---

### IDE & Editor Options

| Tool              | Platform        | Pros                                                                 | Cons                                                      |
|-------------------|-----------------|----------------------------------------------------------------------|-----------------------------------------------------------|
| **Visual Studio** | Windows only    | Complete IDE, strong debugger, GUI tools, MSVC integration           | Heavy install, Windows-only, project setup can be complex |
| **CLion**         | Cross-platform  | Smart refactoring, deep C++ support, CMake built-in, JetBrains polish | Paid (student license free), resource-heavy               |
| **VS Code**       | Cross-platform  | Lightweight, extensible via plugins, good IntelliSense + debugging    | Requires setup of extensions, less deep C++ refactoring   |
| **Vim/Neovim**    | Cross-platform  | Fast, customizable, works in terminal, great for remote dev           | Steep learning curve, needs plugin setup                  |
| **Emacs**         | Cross-platform  | Highly extensible (LSP, org-mode), powerful for advanced users        | Steep learning curve, fewer modern IDE features           |
| **[Online Editor](https://www.onlinegdb.com/online_c++_compiler)**        | Web page		  | Easy access | Small code only |
| **Peng’s Choice** | Mac, Windows, Linux | CLion on Mac/Windows for consistent IDE workflow; Vim on Linux for fast editing & remote work | Students may prefer simpler editors when starting out     |

## 0. Baby Steps in C++

First step.

```cpp
#include <iostream>
#include <string>
#include <cstdio>

int main() {
    std::string message = "Hello C++ BootUp!";
    std::cout << message << std::endl;
    printf("%s\n", message.c_str());

    // primitive variable
    int n = 5;
    std::string messages[] = {
            "C++",
            "this",
            "is",
            "so",
            "much",
            "fun"
    };

	// TODO: print each messsage on the same line

	// TODO: print each messsage one per line

	// TODO: print each message back to front

	// TODO: print every each word, one per line, like "C++"/"is"/"much"
}
```

Second step:

```c++
#include <iostream>

class Food {
public:
    std::string name;
    int expire_in_days;

public:
    Food(const std::string &name, int expire_in_days) : name(name), expire_in_days(expire_in_days) {
    }

    Food() {
        name = "";
        expire_in_days = 0;
    }
};

int main() {
    Food foods[5] = {
        Food("cake", 2),
        Food("apple", 30),
        Food("banana", 15),
        Food("coffee", 90),
        Food("fish", 3),
    };

    Food food = foods[0];
    int lowest_expire_in_days = foods[0].expire_in_days;
    for (int i = 0; i < 5; ++i) {
        if (foods[i].expire_in_days < lowest_expire_in_days) {
            lowest_expire_in_days = foods[i].expire_in_days;
        }
    }

    std::cout << "I should eat " << food.name << " first !" << std::endl;
}

// (눈_눈)
```

---
<img width="30%" height="360" alt="image" src="https://github.com/user-attachments/assets/0b387421-0b5f-4234-b8a3-73516a79f88d" />

Take a break...
---

### "I thought you are a pro?!"

- Readable code vs unreadable code
- "It should work"
- Commented code left in code without reason
- "Magic" contants in code without explanation
- Repeated code block withour clear reaason
- "I lost my work because computer crashed"
- "I wrote the code so I know it's right. No need to write test"
- Debugging code like print left in submitted code
- Weird indent and formatting and extra newlines ("Dude, do you even format code?")

| C++ Code Smell | The "Bruh" Move (Bad) | The "Pro" Move (Clean) |
| :--- | :--- | :--- |
| **Magic Constants** | `if (val > 42) { ... }` | `const int MAX_RETRY_COUNT = 42;`<br>`if (val > MAX_RETRY_COUNT) { ... }` |
| **"It should work"** | "I compiled it and it didn't crash once,<br>so it's basically production-ready." | Writing **Unit Tests** (GTest/Catch2) to<br>validate edge cases and memory safety. |
| **Ghost Code** | `// double old_calculation = x * y;`<br>`// return old_calculation;` | **Delete it.** If it's not active, it shouldn't<br>be in the file. Trust your Git history. |
| **Magic Explainers** | `x = x << 1; // shift left` | `x = x << 1; // Double the buffer size` |
| **Copy-Pasta** | Logic repeated in `calcA()` and `calcB()`<br>with minor tweaks. | **DRY (Don't Repeat Yourself).** Use<br>templates or helper functions. |
| **The Crash Excuse** | "My IDE hung and I lost the last<br>3 hours of my implementation." | **Atomic Commits.** Push small, working<br>chunks to your branch frequently. |
| **Debug Litter** | `std::cout << "got here" << std::endl;`<br>left in a merged Pull Request. | Use a **Logging Library** (like spdlog) or<br>clean up all traces before submitting. |
| **Chaos Formatting** | `if(x){foo();`<br>`}else{  bar(); }` | Use a `.clang-format` file to ensure<br>identical styling across the team. |

### More Readibility

What the heck does this do?

```c++
#include <iostream>

#define _(x) std::cout << (char)(x)
#define __ int
#define ___ main
#define ____ return

__ ___() {
    __ _ = 72;
    _(_);
    _ += 29;
    _(_);
    _ += 7;
    _(_);
    _(_);
    _ += 3;
    _(_);
    _(32);
    _(67);
    _(43);
    _(43);
    _(32);
    _(66);
    _(111);
    _(111);
    _(116);
    _(85);
    _(112);
    _(33);
    std::cout << std::endl;
    ____ 0;
}
```

### More on testing

- Own our code: We, not the teacher, grader, team member, manager, boss, are responsible to show our code is correct.
- Don't trust human: AI hulicates, but human does too. Use (testing) code to test code.
- Testing are for our future self or others to not mess with our code.
- Don't trust the test either.
- Real bug fix in big project takes time. Treat your code as it could cost lives. And sometime it does.
- Assume code doesn't work if it's not properly tested.
- TDD (Test driven development) is not a hoax. It's not a silver bullet either. See [this](https://youtu.be/a6oP24CSdUg?si=UAVaHZyeGlyNS5Gp).

| Principle | The "Bruh" Mindset | The "Pro" Reality |
| :--- | :--- | :--- |
| **Code Ownership** | "The grader or manager will tell me if it's wrong." | **You** are the only one responsible for proving your code is correct. |
| **Human Reliability** | "I reviewed it twice, it's fine." | **Humans hallucinate.** AI does too. Only (testing) code can reliably test code. |
| **Future-Proofing** | "I'll remember why I did this." | **Tests are for the 'Future Stranger'** (which is you in 6 months) to prevent breakage. |
| **Test Skepticism** | "The tests passed, so we're 100% safe." | **Don't trust the test either.** A flawed test gives a false sense of security. |
| **Stakes & Safety** | "It's just a bug; we'll patch it later." | **Treat code like it costs lives.** In C++, a memory leak or overflow often does. |
| **Validation** | "It compiled and ran once on my machine." | **Assume it's broken** if it isn't backed by a robust, repeatable test suite. |
| **Methodology** | "TDD is a hoax/academic waste of time." | **TDD is a design tool.** It's not a silver bullet, but it forces clarity before implementation. |

### Exercise: 

- Write code to find the smallest value in an integer array
  - Is your code correct? Add test for it
  - Is your test correct?
- Make your code as unreadable as possible (because why not)
- Debug using IDE (Breakpoint, Step into, Step over, examining variables)
- Complete [exercise A](https://github.com/a-teaching-goose/UWB-342-BootUp-2026-March/blob/main/notes/exercise_A.md#exercise-a-its-not-going-anywhere)
- Start exercise B with a fixed-capacity queue

---

<img width="30%" height="940" alt="image" src="https://github.com/user-attachments/assets/6e676035-f5d4-4f70-abb4-24be8ed64a35" />

Take a break...
---

## 1. Compilation: Code → Binary

> “Programs must be written for people to read, and only incidentally for machines to execute.”  
> — Harold Abelson, *Structure and Interpretation of Computer Programs*

Unlike Java (compile to bytecode + JVM), C++ compiles directly to native machine code.

**What does that mean?**  
- **Bytecode (Java):** When you compile Java, the compiler translates your `.java` source files into an intermediate format called **bytecode** (stored in `.class` files). Bytecode is not tied to any specific CPU. Instead, it runs inside the **Java Virtual Machine (JVM)**, which interprets or JIT-compiles it into real instructions for the host system. This makes Java **portable** across platforms, because the same `.class` file can run anywhere there’s a JVM.  
- **Native Machine Code (C++):** When you compile C++ with `g++` or `clang++`, your source files are translated directly into the **machine instructions** that your CPU executes (an `.exe` on Windows, or a binary on Linux/macOS). This means the program runs **fast**, without the overhead of a virtual machine — but it’s also tied to the specific platform and architecture you compiled for (e.g., x86 vs ARM).

Before diving into the examples, it’s important to understand the different ways to compile and build C++ projects:  

1. **Directly with a compiler (e.g., `g++`)** – You can invoke the compiler manually to turn your `.cpp` source files into executables. This works well for very small projects but quickly becomes tedious when there are many files or libraries to link.  

2. **Using `make` with a Makefile** – `make` is a build automation tool. Instead of typing long compiler commands, you describe the build rules once in a Makefile. `make` then only recompiles the files that have changed, which saves time and reduces mistakes.  

3. **Using CMake** – CMake is a higher-level, cross-platform build system generator. Instead of hardcoding compiler commands, you describe your project in `CMakeLists.txt`, and CMake generates the proper build files for your platform (Makefiles, Visual Studio solutions, Ninja build files, etc.). This makes it more portable and easier to manage large projects.  

Each option has trade-offs: using the compiler directly is simplest but least scalable, Make is lightweight but Unix-centric, while CMake offers portability and advanced configuration but introduces an extra layer of tooling. Finally, when working in an IDE like CLion or Visual Studio, the **green “Run/Build” button** is essentially a shortcut that calls into your configured build system (often CMake under the hood) and then launches the executable.

**Minimal program:**

```cpp
#include <iostream>
int main() {
    std::cout << "Hello C++ BootUp!" << std::endl;
    return 0;
}
```

**Method 1: Compile & run:**

```bash
# g++        → GNU C++ compiler
# -std=c++17 → Use the C++17 language standard
# -O2        → Enable level 2 optimizations (good balance of speed and compile time)
# -Wall      → Enable most common warnings
# -Wextra    → Enable additional (extra) warnings
# -o helloworld → Name of the output binary (instead of default a.out)
# helloworld.cpp → Your source code file
g++ -std=c++17 -O2 -Wall -Wextra -o helloworld helloworld.cpp
./helloworld
```

👉 The `-o helloworld` flag tells the compiler the **name of the output binary**.  
- On **Linux and macOS**, executables usually don’t have a `.exe` extension — you just run them with `./helloworld`.  
- On **Windows**, compilers typically add `.exe` automatically (e.g., `helloworld.exe`).  
- If you omit `-o`, the default output file is usually named `a.out`.  

### Method 2: Using Makefile

```make
CXX := g++
CXXFLAGS := -std=c++17 -O2 -Wall -Wextra
SRC := $(wildcard src/*.cpp)
OBJ := $(SRC:.cpp=.o)
BIN := mariolab

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(OBJ) $(BIN)
```

### Method 3: Using CMakeLists.txt

```cmake
cmake_minimum_required(VERSION 3.15)
project(mariolab LANGUAGES CXX)

# Require C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Default build type = Release if not set
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

# Collect all .cpp files from src/
file(GLOB SRC_FILES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/*.cpp")

# Define executable
add_executable(mariolab ${SRC_FILES})

# Compiler options
if(MSVC)
  target_compile_options(mariolab PRIVATE /W4 /permissive-)
else()
  target_compile_options(mariolab PRIVATE -Wall -Wextra)
  target_compile_options(mariolab PRIVATE $<$<CONFIG:Release>:-O2>)
endif()

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
```

---

<img width="30%" height="2048" alt="image" src="https://github.com/user-attachments/assets/dfa27aef-ec74-485b-8f1c-e80527ba4422" />

Take a break...

---

## 3. Memory System

### 3.1 Stack vs Heap

In C++, memory is managed through the stack and the heap, two distinct areas that balance speed, size, and flexibility in different ways.

The stack is like cash in your pocket: it’s right there for you to use instantly, no paperwork, no waiting — but your pocket can only hold a small amount, and once you leave a function it all gets emptied out. The heap, on the other hand, is like money in the bank: there’s a lot more available and it’s shared across your whole program, but using it takes more effort — you have to request space, wait for it, and when you’re done you must return it properly, or else you risk “losing” it. Knowing when to use the stack for speed and simplicity, and when to use the heap for flexibility and size, is key to writing efficient and reliable C++ programs.

| Concept | Analogy | Characteristics | In C++ |
|---------|----------|-----------------|--------|
| **Stack** | Your **wallet** | - Small, fast, automatic<br>- Last in, first out (LIFO)<br>- Cleared when you leave a function | Local variables (e.g., `int x = 5;`) |
| **Heap** | Your **bank account** | - Large, flexible, manual<br>- Access is slower<br>- Must manage deposits/withdrawals yourself | Dynamically allocated objects (e.g., `new int(5);`) |

<img width="50%" height="1472" alt="image" src="https://github.com/user-attachments/assets/696fa1c2-8532-4093-b896-b732b9329c16" />

### 3.2 Accessing Memory Locations (Addressing)

In C++, there are three common ways to work with memory: variable names, references, and pointers. A variable name gives you direct access to a piece of memory by its declared identifier, while a reference acts as an alias — essentially another name for the same memory, ensuring you always work with the original object. A pointer, on the other hand, is a variable that holds a memory address, giving you the power to point to different objects and control memory manually with * and &. One key distinction between C++ and Java is that in C++, a pointer truly stores a raw address in memory, which you can manipulate directly, while in Java, what we call a “reference” is a managed handle to an object — you don’t see or control the actual memory address, and the garbage collector ensures cleanup instead of requiring you to free memory yourself.

- **Variable name:** Direct access to a memory location by its declared name (e.g., `int a = 10;`).  
- **Reference:** An alias to an existing variable; another name for the same memory (e.g., `int& ref = a;`).  
- **Pointer:** Stores the memory address of a variable; use `*` to access or modify the value (e.g., `int* p = &a;`).  

```cpp
#include <iostream>

void bumpByValue(int x) { x++; }
void bumpByRef(int& x) { x++; }
void bumpByPtr(int* x) { if (x) (*x)++; }

void swapByValue(int a, int b) { int t=a; a=b; b=t; }
void swapByRef(int& a, int& b) { int t=a; a=b; b=t; }
void swapByPtr(int* a, int* b) { int t=*a; *a=*b; *b=t; }

int main() {
    int a = 10, b = 20;
    bumpByValue(a);
    bumpByRef(a);
    bumpByPtr(&a);

    swapByValue(a, b);
    std::cout << a << "," << b << "\n";

    swapByRef(a, b);
    std::cout << a << "," << b << "\n";

    swapByPtr(&a, &b);
    std::cout << a << "," << b << "\n";
}
```

👉 In Java, objects are always passed by value **of reference**. In C++, you explicitly choose **value/ref/pointer**.

---

## 3.3 Pointer Arithmetic with Arrays

```cpp
#include <iostream>

// Finds the element-wise maximum between two arrays of length n
void maxArrays(const int* arr1, const int* arr2, int* result, int n) {
    const int* p1 = arr1;
    const int* p2 = arr2;
    int* pr = result;

    for (int i = 0; i < n; ++i) {
        *pr = (*p1 > *p2) ? *p1 : *p2;
        p1++;
        p2++;
        pr++;
    }
}

int main() {
    int a[] = {1, 7, 3, 9, 5};
    int b[] = {2, 6, 4, 8, 10};
    int result[5];

    maxArrays(a, b, result, 5);

    std::cout << "Element-wise max array: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << result[i] << " ";
    }
    std::cout << "\n";
}
```

👉 Demonstrates how pointers can walk through arrays: `p++` moves the pointer by `sizeof(int)` and `*p` accesses the value. This is equivalent to indexing (`arr[i]`), but shows how arrays and pointers are deeply connected in C++.

---

## 3.4 Pointer Arithmetic with Arrays (Returning a New Result Array)

```cpp
#include <iostream>

// Allocate a new array and return pointer to result
int* maxArraysNew(const int* arr1, const int* arr2, int n) {
    int* result = new int[n]; // caller must remember to delete[] this

    const int* p1 = arr1;
    const int* p2 = arr2;
    int* pr = result;

    for (int i = 0; i < n; ++i) {
        *pr = (*p1 > *p2) ? *p1 : *p2;
        p1++;
        p2++;
        pr++;
    }

    return result;
}

int main() {
    int a[] = {1, 7, 3, 9, 5};
    int b[] = {2, 6, 4, 8, 10};

    int* result = maxArraysNew(a, b, 5);

    std::cout << "Element-wise max array: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << result[i] << " ";
    }
    std::cout << "\n";

    delete[] result; // important to avoid memory leak
}
```

This version dynamically allocates the result array and returns it. 

In production C++, prefer `std::vector<int>` or smart pointers to manage memory automatically.

⚠️ **Memory Leak Warning:** If you forget the `delete[] result;` line, tools like Valgrind will show output.

### ✍️ Exploration: Estimate Stack Size (MB)

```cpp
/*
Goal: Hold a ~1 MB local array in each recursive call and count how many
  calls we can make before the program runs out of stack space.

  How it works:
  - Each call to foo() allocates a 1,048,576-byte array on the stack.
  - We print the recursion depth (i) to show how many frames are active.
  - Recursing indefinitely will eventually overflow the stack and crash.
  - The approximate stack used at the moment of crash ≈ i × 1 MB.

  How to check your system's stack limit (macOS/Linux):
    ulimit -s      # prints stack size in kilobytes (e.g., 8192 = 8 MB)

  You can temporarily raise it for testing:
    ulimit -s 65536   # sets stack to 64 MB for this shell

  Notes:
  - This intentionally crashes to reveal the stack limit. Run only in a safe environment.
  - Compilers may optimize unused arrays away, so we write into the array to keep it.
  - The actual limit depends on OS, shell limits, compiler, and build type.
  - A SIGSEGV handler could be used to print the last value before crashing, but we
    keep it simple here.
*/

#include <cstdio>

void foo(int i) {
    // 1 MB on the stack per call
    constexpr int size = 1024 * 1024;
    char data[size];

    // Touch the memory so the compiler can't optimize it away
    data[0] = static_cast<char>(i);

    // Print current recursion depth and flush so it shows before crash
    std::printf("%d\n", i);
    std::fflush(stdout);

    // Recurse to allocate another 1 MB stack frame
    foo(i + 1);
}

int main() {
    foo(0);
}
```

Food for thoughts: What do you get when running this? And what does it mean?

---

<img width="30%" height="460" alt="image" src="https://github.com/user-attachments/assets/b311022e-fee3-47b8-a88d-3d74dfc4a214" />

Take a break...
---

### Exercise: 
- Continue exercise B with a queue whose size can be definted during creation
- Convert into a cyclic pattern
- Split file into multiple files, and update CMake accordingly
- Replace var size with a function, and add unit test using, show how to debug
- Discuss:
  - Alarm mechanism when the queue is getting long
  - Add function to return the longest wait time
  - What if the queue is not strictly FIFO? Does
-  Is there memory leak in the code?

---

## Key Differences vs Java

1. **Compilation:** Java → bytecode/JVM. C++ → native binary.
2. **Memory model:** Java hides addresses; C++ exposes `&`, pointers.
3. **Passing:** Java passes primitives by value and objects by value of reference. C++ lets you choose value, reference, or pointer for any type.
4. **Polymorphism:** Java methods are virtual by default. In C++, you must mark with `virtual` and use references/pointers to enable dynamic dispatch; value semantics can slice.
5. **Lifetime:** Java has GC. C++ uses RAII and destructors; raw pointers require explicit delete.
6. **Slicing:** Only in C++ if you store/pass a derived object **by value** as its base.

---

**End of Notes — Good luck for your study and happy coding!**

<img width="30%" height="768" alt="image" src="https://github.com/user-attachments/assets/5c5e9e92-275b-483a-917c-ad71ad31df52" />


---

© 2026 Peng Du. All rights reserved.  
Unauthorized use, reproduction, or distribution is prohibited.
