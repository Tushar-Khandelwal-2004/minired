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

- Compile-time errors
- Linker errors

and understood at which stage each type of error occurs.

Another important thing I learned was why multi-file projects exist and why large projects are split into multiple source and header files instead of keeping everything in a single file.