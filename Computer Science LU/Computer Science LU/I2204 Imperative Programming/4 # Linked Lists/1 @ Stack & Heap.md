# Stack
When creating a function inside the stack memory, every variable created inside this function will be de-allocated after the end of the function, so trying to point at variable inside a function is useless.
This where heap memory comes into play

# Heap
When creating a variable inside the heap memory, it will stay there unless the programmer specifies it should be de-allocated.

The following functions are located in the `<stdlib.h>`
- To create a variable inside the memory we use the function `malloc();` which allocates a space in the memory for a variable and returns a pointer to it. Wont go too much into detail since you already know how to use it.
```c
int *ptr = (int*)malloc(sizeof(int) * x);
```
- To free up the space in the memory created with malloc, we use the function `free();` which functions pretty easily like in the following example. (Note that it will free the memory for an array even tho we only put the pointer to the start of the array).
```c
free(ptr);
ptr = NULL; //better to do this so you wont get any errors later in the code
```
