# vector-math
A small library that implements useful 2D and 3D math functions, primarily dealing with vectors and matrices.

The primary goal for all functions in this library is to avoid memory allocations as much as possible.
Structs should be passed by value so input remains unchanged. Only the output parameter should receive a reference.

# style-guide
All of the code in this repo must respect the 42 school's official coding style (The Norm / La Norme).
Including but not limited to:
1. Functions
  - Functions must contain 25 lines or less. (This rule applies to practically all scopes.)
  - Functions must not have more than 4 parameters.
  - Functions must not have more than 5 local variables.
  - Variables cannot be initialized during declaration. This includes arrays.
  - Function names, local variables, and struct members must be respectively aligned within scope.
2. Misc
  - Do-While and For-loops are forbidden. Use While.
  - Nested ternary-statements are forbidden. Just stop.
  - Any flow-control must be followed by a newline.
    - If curly-braces are omitted (single-statement), the next line must also be tabulated.
      - Even if no statement is needed, a semicolon must still be present.
  - Lines must not reach beyond column 80.
