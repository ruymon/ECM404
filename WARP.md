# WARP.md

This file provides guidance to WARP (warp.dev) when working with code in this repository.

## Repository Overview

This is a C programming exercises repository for academic coursework (ECM404), organized into exercise lists (L1, L2, L3, etc.) with individual `.c` files containing solutions to programming problems. The repository includes a Python organization script to manage the exercise file structure.

## Development Commands

### Compiling C Programs

```bash
# Compile a single exercise (basic)
gcc L1/ex1.c -o L1/ex1

# Compile with debugging symbols
gcc -g L1/ex1.c -o L1/ex1

# Compile with warnings enabled
gcc -Wall -Wextra L1/ex1.c -o L1/ex1

# Compile programs that use math functions (like L3/main.c)
gcc -lm L3/main.c -o L3/calculator
```

### Running Programs

```bash
# Run a compiled exercise
./L1/ex1

# Run the calculator program
./L3/calculator
```

### Repository Management

```bash
# Run the Python organization script
python organize.py

# Remove compiled executables from all lists
python organize.py  # Choose option 3

# Remove compiled executables from specific list
python organize.py  # Choose option 4
```

## Project Architecture

### Directory Structure

- **L1/, L2/, L3/, etc.**: Exercise lists containing individual C programs
  - Each contains `ex1.c`, `ex2.c`, etc. files with complete standalone programs
  - L3 contains a more complex calculator program (`main.c`)
- **class-problems/**: Additional practice problems from class
- **organize.py**: Python utility script for file organization
- **.vscode/settings.json**: VS Code configuration with C file associations

### Code Organization Patterns

**Exercise Structure**: Each exercise file typically follows this pattern:
- Standard C includes (`stdio.h`, `stdlib.h`)
- Problem statement in block comments
- `main()` function with the solution
- Simple, focused implementations for learning concepts

**Programming Concepts Covered**:
- L1: Basic I/O and "Hello World" style programs
- L2: Conditional statements and comparisons
- L3: Advanced calculator with functions, math operations, and menu systems
- Functions, loops, arrays, and user input handling

### File Naming and Organization

The repository uses two organizational approaches:
1. **Current**: Flat structure with `ex1.c`, `ex2.c` directly in list directories
2. **Legacy**: Nested structure with `ex1/main.c`, `ex2/main.c` subdirectories

The `organize.py` script converts from legacy to current structure automatically.

## Common Development Workflow

1. **Creating New Exercises**: Add new `.c` files following the naming pattern `exN.c` in the appropriate list directory
2. **Compiling**: Use `gcc` with appropriate flags, especially `-lm` for math functions
3. **Testing**: Run programs interactively as most exercises require user input
4. **Organization**: Use `organize.py` when working with exercise directories that need restructuring
5. **Cleanup**: Regularly remove `.exe` files using the organization script

## Special Considerations

- Programs are written in Portuguese (comments, prompts, variable names)
- Many exercises require interactive user input via `scanf()`
- L3/main.c requires the math library (`-lm` flag) for trigonometric and power functions
- The organization script provides bilingual feedback and handles both file organization and cleanup tasks
- VS Code is configured with C file associations for better development experience
