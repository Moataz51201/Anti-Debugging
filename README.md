# Bypassing Debugging Detection through PEB Patching

This repository demonstrates how to bypass debugging detection in Windows by modifying the `BeingDebugged` flag in the Process Environment Block (PEB). This technique can be used to bypass simple anti-debugging mechanisms. 

The repository contains both Assembly (ASM) and C code for patching the `PEB->BeingDebugged` flag, allowing a process to avoid detection by debuggers.

## Table of Contents
- [Introduction](#introduction)
- [Getting Started](#getting-started)
- [Code Structure](#code-structure)
- [Usage](#usage)
- [Disclaimer](#disclaimer)

## Introduction

The PEB is a Windows OS data structure that stores critical information about the current process, including a flag known as `BeingDebugged`. This flag indicates whether the process is being debugged, making it a target for debugging detection techniques. By patching this flag to `0`, we can bypass basic anti-debugging checks.

## Getting Started

### Prerequisites
- Windows OS
- Visual Studio (for compiling C code)
- An assembler (e.g., MASM for Assembly code)

### Environment Setup
1. **Clone the repository** or download the `.ASM` and `.C` files manually.
2. Make sure your development environment is set up to compile both C and Assembly code.

## Code Structure

- **ASM Code (`patch.asm`)**: Contains the Assembly code for locating the PEB, checking the `BeingDebugged` flag, and patching it if needed.
- **C Code (`main.c`)**: Provides a C-based implementation that calls the Assembly functions to access and patch the PEB.

### ASM Code - `patch.asm`
This file contains:
- `getPEB`: A function to locate the PEB.
- `PEBPatcher`: A function to check the `BeingDebugged` flag and patch it if it is set.

### C Code - `main.c`
This file contains:
- `main`: The main function that interacts with the PEB using Assembly functions to detect and patch the `BeingDebugged` flag.
- `MessageBoxW`: Provides a confirmation message upon successful patching.

## Usage

1. **Compile the Code**:
   - **For ASM**: Use an assembler like MASM to compile `patch.asm`.
   - **For C**: Use a C compiler (e.g., Visual Studio) to compile `main.c`, linking it with the compiled ASM code.

2. **Run the Executable**:
   - Run the compiled executable to see the PEB patch in action. If the `BeingDebugged` flag is set, the program will patch it to `0` and display a success message.

## Proof of Concept

Running the executable shows the PEB’s `BeingDebugged` flag before and after patching, confirming that the anti-debugging check is bypassed. 

## Disclaimer

This code is intended for educational and research purposes only. Modifying system structures like the PEB can be potentially harmful and may violate software agreements. Use responsibly.

---

Happy exploring!
