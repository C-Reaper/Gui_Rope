# Project README

## Overview
This project is a simple 2D rope simulation built using C and a custom graphics library. The user can interact with the rope by clicking and dragging on its segments.

## Features
- 2D graphical representation of a rope.
- Interactive dragging of rope segments.
- Simple physics-based movement of the rope.

## Project Structure
```
<project>/
├── build/              # .exe files produced by Main.c
├── src/                # source code
│   ├── Main.c          # Entry point
│   └── Rope.h          # Header file for the rope module
├── Makefile.linux      # Linux Build configuration
├── Makefile.windows    # Windows Build configuration
├── Makefile.wine       # Wine Build configuration
├── Makefile.web        # Emscripten Build configuration
└── README.md           # This file
```

### Prerequisites
- C/C++ Compiler and Debugger (GCC, Clang)
- Make utility
- Standard development tools

## Build & Run
### Linux
To build the project on Linux:
```sh
cd <project>
make -f Makefile.linux all
make -f Makefile.linux exe
```

### Windows
To build the project on Windows:
```sh
cd <project>
make -f Makefile.windows all
make -f Makefile.windows exe
```

### Wine
To build the project for Windows using Wine:
```sh
cd <project>
make -f Makefile.wine all
make -f Makefile.wine exe
```

### Web
To build and run the project in a web browser using Emscripten:
```sh
cd <project>
make -f Makefile.web all
make -f Makefile.web exe
```