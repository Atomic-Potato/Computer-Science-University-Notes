Variables of type `(void *)` are pointers to data of unspecified type. In this context, void acts as a universal type.
A program can convert a pointer to any type of data `(int*, char*, ...)` to a pointer to void `(void *)` and back to the original type without loosing information.

Example on usage and casting
![[example on void pointer.jpg | 500]]

# malloc();
Stands for memory allocation, which means it preserves an empty space in the memory for the current process so we could use it later.
```cpp
var *P;

P = (cast*)malloc(int size)
//We give the function the size of how much empty memeory we want in bits
//The function returns a void pointer to the address of the first element in the allocated memory (a null pointer if allocation fails)
//We pick the type of pointer we want by just casting that type and store in a pointer variable of the same type
```
