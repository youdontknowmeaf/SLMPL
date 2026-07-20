# SLMPL

> Simple, Lightweigh, Multi Purpose Library/Wrapper

## Features

* **Portability:** Strict C89 standard and use of SDL1.2 and OpenGL2.
* **Modularity:** Each part of the lib is it's own .c file so you can replace certain parts without breaking anything.
* **Flexability:** Tested against 3 major C compilers (gcc, tcc, pcc) and 2 major C libraries (GlibC, MUSL).

## Prerequisites

Before you compile, install these:
* [SDL1.2](https://github.com/libsdl-org/SDL-1.2)
* [OpenGL2](https://www.opengl.org/)
* That's it. Only 2 dependencies!

## Installation

1. Clone the repo:
   ```bash
   git clone https://github.com/youdontknowmeaf/SLMPL.git
   ```
2. CD into the folder and run the makefile matching your C compiler.
  Makefile - GCC
  TCC.mk - TCC
  PCC.mk - PCC
  ```bash
  make
  make -f TCC.mk
  make -f PCC.mk
  ```
3. Additionally you can build the example app (recommended)
   ```bash
   make (-f {your_compiler}.mk) test
   ./a.out
   ```

## Contribute

1. Fork the repo on GitHub and download your fork locally.
2. Do whatever you want as long as you keep support for all the Makefiles and C89.
    * If you say - want to make a version of (idk) *_render.c for PSP and you need to use a non-c89 toolchain then feel free to do so, the C89 compatibility is for the main files.
3. Make a new branch and push your changes to it then make a merge request.

Bug reports, ideas, etc. are welcome: @fuckinfuck81 (discord)
