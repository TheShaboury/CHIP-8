# CHIP-8 Emulator in C++

A CHIP-8 emulator written from scratch in C++ using SDL2 for graphics and input.

I've always been fascinated by how games like DOOM can run on different devices and how emulators actually work. That curiosity, along with my background in embedded software, led me to build my own CHIP-8 emulator.

I wanted to spend more time writing C++ while exploring low-level programming and understanding what's happening under the hood, from instruction execution and registers to memory and its constraints.

## Features

- Implementation of all 34 CHIP-8 instructions
- Fetch-decode-execute cycle
- ROM loading into emulated memory
- CHIP-8 fontset initialization
- Registers, stack, program counter, and index register
- Random number generation
- Function pointer table for opcode dispatch
- CHIP-8 hexadecimal keypad input
- 64 × 32 monochrome display
- SDL2 platform layer for graphics and input
- Main execution loop

## How It Works

The emulator follows the fetch-decode-execute cycle:

1. **Fetch:** Read the next instruction from memory using the program counter.
2. **Decode:** Identify the opcode and extract its operands.
3. **Execute:** Perform the operation, such as arithmetic, memory access, control flow, input handling, or graphics.
4. **Repeat:** Continue processing instructions through the main loop.

The emulator maintains the state of the CHIP-8 virtual machine, including memory, registers, stack, timers, display, and keypad. SDL2 handles graphics rendering and input on the host system.

## Technologies

- **C++** for the emulator implementation
- **SDL2** for graphics and input
- **MSVC / Windows SDK** for command-line compilation on Windows

## ROMs

The emulator can run existing CHIP-8 ROMs, including:

- Tetris
- Tank
- Pong

You'll need to provide your own ROM files. Make sure you have permission to use and distribute any ROMs you obtain.

## Building from the Command Line (Windows)

You can compile the project into an executable without opening the Visual Studio IDE using the Microsoft C++ Build Tools and MSBuild.

### Requirements

- [Visual Studio Build Tools](https://visualstudio.microsoft.com/visual-cpp-build-tools/) with the **Desktop development with C++** workload
- Windows SDK
- [SDL2 development libraries](https://github.com/libsdl-org/SDL/releases)

### 1. Clone the Repository

```bash
git clone https://github.com/TheShaboury/CHIP-8.git
cd CHIP-8
```

### 2. Configure SDL2

Download and extract the SDL2 development package that matches your compiler and target architecture.

Configure the project to locate the SDL2 headers and libraries. The required include directories, library directories, and linker dependencies must match your local SDL2 installation.

### 3. Open a Build Environment

Open **x64 Native Tools Command Prompt for Visual Studio** from the Start menu. This provides access to the MSVC compiler, linker, Windows SDK, and MSBuild.

Navigate to the repository directory.

### 4. Compile the Project

Use MSBuild with the solution or project file included in the repository. Replace the example filenames with the actual filenames if they differ.

Using a solution file:

```bat
msbuild CHIP-8.sln /p:Configuration=Release /p:Platform=x64
```

Or build the project file directly:

```bat
msbuild CHIP-8.vcxproj /p:Configuration=Release /p:Platform=x64
```

The executable will be generated in the project's configured output directory, typically under a `Release` or `x64\Release` folder.

### 5. Run the Emulator

The emulator accepts three command-line arguments:

```text
<scale> <delay> <rom_path>
```

Example:

```bat
CHIP-8.exe 10 2 "C:\ROMs\Tetris.ch8"
```

- `scale`: Display scaling factor.
- `delay`: Execution delay parameter.
- `rom_path`: Path to the CHIP-8 ROM file.

Use the argument values expected by your implementation.

### Runtime Dependencies

Ensure `SDL2.dll` is available beside the executable or in a directory on your system's `PATH`.

If you distribute the executable, include the required SDL2 runtime DLL and account for any additional runtime dependencies. Compiling to an `.exe` does not automatically make it fully standalone.

## References

- [CHIP-8 Technical Reference by Cowgod](http://devernay.free.fr/hacks/chip8/C8TECH10.HTM)

I also studied other CHIP-8 implementations to learn about different approaches to instruction handling and emulator design.

## About

This project was an opportunity to explore C++ and low-level concepts through hands-on implementation. The code was written manually without AI-generated code, using documentation, existing implementations for learning, and debugging throughout development.
