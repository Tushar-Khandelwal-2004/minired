# Day 0 (19/09/2026)

Today, I set up the Linux development environment for building **MiniRedis**.

I planned to use Ubuntu on WSL2, but it failed every time. WSL was working, and the Docker WSL distribution also worked. I tried installing Debian, and boom, it worked. So the issue was specific to the Ubuntu distribution.

Now, I created the folder structure for the project and put some code inside the `src` folder to check whether everything was working correctly.

## Learning

### CMakeLists.txt

`CMakeLists.txt` is similar to `package.json`. You can think of it as the build configuration file of the project.



# Day 1 (21/09/2026)

Today, I deep-dived into some of the core foundations of C++ project development.

I learned about:

- The Compiler
- The Linker
- CMake
- Make

I also learned why `.o` (object) files are needed and how the compilation process is split into multiple stages instead of directly generating the final executable.

I explored the difference between:

- Compile-time errors -> missing declaration gives a compile error
- Linker errors -> Happens when the Linker is not able to found the actual contents which were promised (missing definition gives linker error)

and understood at which stage each type of error occurs.

Another important thing I learned was why multi-file projects exist and why large projects are split into multiple source and header files instead of keeping everything in a single file.


# Day 2 (28/09/2026)

Today I learned about RAII, one of the most important concepts in C++.

I started with constructors and destructors. Constructors run automatically when an object is created and destructors run automatically when an object goes out of scope. I also learned that objects are destroyed in the reverse order of their creation.

To understand this better, I created a `Noisy` (learn/day02_raii.cpp) class which printed messages when objects were created and destroyed. I tested nested scopes and early returns and saw that destructors still run even when a function returns early.

I then learned the difference between stack and heap allocation. Objects created normally are destroyed automatically when they go out of scope, but objects created with `new` are not destroyed automatically and can cause memory/resource leaks if `delete` is forgotten.

Next, I learned about ownership. Copying an object that owns a resource can be dangerous because multiple objects may try to release the same resource, causing bugs such as double close or double free.

Finally, I learned move semantics. Instead of copying ownership, ownership can be transferred from one object to another. After the move, the old object no longer owns the resource, ensuring that the resource is released only once.

The main takeaway from today was that a resource should have only one owner, and RAII helps manage resources automatically using constructors and destructors.

After understanding the concepts, I implemented my first real project class: `Fd` (`src/util/fd.h`).

The purpose of this class is to own a Linux file descriptor and automatically close it when the object goes out of scope.

While implementing it, I learned about:

- `#pragma once`
- `explicit` constructors
- `static constexpr`
- Deleting copy constructor and copy assignment operator
- Move constructor
- Move assignment operator
- Default function arguments

I implemented the following functions:

- Default constructor
- Constructor that takes ownership of a file descriptor
- Destructor
- Move constructor
- Move assignment operator
- `get()`
- `valid()`
- `release()`
- `reset()`

Copying was disabled to prevent multiple objects from owning the same descriptor.

I then created `learn/day02_fd_test.cpp` to test the class. For the first time, I used Linux system calls such as `open()` and `close()` and learned that the kernel returns a file descriptor (an integer) which is used to access files and other resources.

Using `std::move()`, I transferred ownership of a descriptor from one `Fd` object to another and verified that the original object became invalid after the move.

Finally, I tested the destructor and confirmed that the descriptor was closed exactly once. This proved that the ownership transfer logic was working correctly and that the RAII wrapper was doing its job.

