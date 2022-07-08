A header file is a file with extension `.h` which contains `C function declerations and macro definitions` and to be shared between several source files.

There are two types of header files:
- ones the programmer writes `#include "stack.h"`
- ones that come with the compiler `#include<stdio.h>`

A simple practice in C programs is that we keep all the
- *constants / macros / system wide global variables / function prototypes*

in header files and include that header file wherever is required
![[Pasted image 20220610144445.png]]

# Rules
### |1|
Each module with its `.h` and `.c` file should correspond to a clear piece of functionality
*Conceptually, a `module` is a group of declarations and functions can be developed and maintained separately from other modules, and perhaps even reused in entirely different projects*

### |2|
![[Pasted image 20220610144845.png]]

### |3|
Set up program-wide functions with an `extern` declaration in the `header file`, and a defining declaration in the  `.c` file
![[Pasted image 20220610145014.png]]

### |4|
Keep a module's internal declarations out of the header file.

### |5|
Every header file *A.h* should `#include` every other header file that requires to compile correctly but not more.

### |6|
The `A.c` file should first `#include` its `A.h` file, and then any other headers required for its code
![[Pasted image 20220610145250.png]]

### |7|
Never `#include` a `.c` file