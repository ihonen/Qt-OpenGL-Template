# Qt/OpenGL Template

# About

This template is an example as to how to build a Qt GUI around a view that is
renderer with OpenGL. The example is based on ["Hello Triangle" from Learn OpenGL](https://learnopengl.com/Getting-started/Hello-Triangle).

![](screenshot.png)

There are many similar examples out there, but it seems to me that most of them
don't properly separate **application** code from **UI** code. Generally speaking,
the business logic of an application should not depend on the framework used
to implement the application's user interface. To that end, this example clearly
separates the two:

- `Source/Gui` contains **Qt-dependent UI layer code** and is **written in C++**
- `Source/Renderer` contains **OpenGL-dependent application layer code** and is **written in C**

In other words, the OpenGL-based `Renderer` is independent of the Qt-based `Gui`.
This way we could relatively easily swap Qt for any other framework to implement
`Gui` without having to make any changes to `Renderer`.

This example uses GL3W to load OpenGL functions.

## Build & run (Linux)

```
Scripts/Linux/bootstrap.sh
cmake -B build -S .
cmake --build build
./build/bin/Example-App
```

## Build & run (Windows)

This should hopefully work, but you'll need to re-evaluate your life choices:
```
Scripts/Windows/bootstrap.ps1
cmake -B build -S .
cmake --build build
./build/Debug/bin/Example-App
```
