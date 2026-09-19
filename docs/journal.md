# Day 0 (19/09/2026)

Today, I set up the Linux development environment for building **MiniRedis**.

I planned to use Ubuntu on WSL2, but it failed every time. WSL was working, and the Docker WSL distribution also worked. I tried installing Debian, and boom, it worked. So the issue was specific to the Ubuntu distribution.

Now, I created the folder structure for the project and put some code inside the `src` folder to check whether everything was working correctly.

## Learning

### CMakeLists.txt

`CMakeLists.txt` is similar to `package.json`. You can think of it as the build configuration file of the project.