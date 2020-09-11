# vector-math
A small library that implements useful 2D and 3D math functions, primarily dealing with vectors and matrices.

The primary goal for this library is to be as self-contained as possible and for all functions in this library is to avoid memory allocations as much as possible. Structs should be used liberally when passing/returning any kind of complex results. These structs should be simple and universal, so that as many functions as possible might make use of them without needing their own struct.
- When the project started, this library had 4 structs, **xy**, **xyz**, **xyzw** (containing only doubles, to be interchangeable with 32-bit ints), and **matrix** (containing only double[4][4]).

This library should also be independent of any other libraries besides math.h for basic math functions. This may change, but the amount of dependencies should be kept absolutely minimal, to keep the library as compatible with other 42 projects as possible. (No forbidden functions, which may change from project to project.)

# style-guide
All of the code in this repo must respect the 42 school's official coding style (The Norm / La Norme).
Including but not limited to:
### Functions
  - Functions must contain 25 lines or less. (Doesn't apply to enums/structs)
  - Functions must not have more than 4 parameters. (Bypassable with arrays/structs)
  - Functions must not have more than 5 local variables. (Bypassable with arrays/structs)
  - Variables cannot be initialized during declaration. This includes arrays/structs.
  - Function names, local variables, and struct members must be respectively aligned within scope.
### Misc
  - Do-While and For-loops are forbidden. Use While.
  - Nested ternary-statements are forbidden. Just stop.
  - Any flow-control must be followed by a newline.
    - If curly-braces are omitted (single-statement), the next line must also be tabulated.
      - Even if no statement is needed, a semicolon must still be present.
  - Lines must not reach beyond column 80.
### Comments
- "C++ comments" are forbidden:
```
// Don't do this.
```
- Block-comments must be in this format:
```
/*
** Don't ask
** why so.
*/
```
- Functions cannot contain comments.
