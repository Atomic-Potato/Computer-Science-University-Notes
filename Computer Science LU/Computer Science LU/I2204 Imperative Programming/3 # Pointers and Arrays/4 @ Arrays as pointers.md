When accessing a variable within and array using `Array[x]`, x is actually an address of the element in the array

==These are equivalent==
```c
array[i] <=> *(array + i)
&array[i] <=> array + i
```

To get the size of an array using `sizeof()`, we do
`sizeof(array)/sizeof(int)`

# Operator precedence in C
![[operators precendence in C.jpg | 500]]

# Passing Arrays
When declaring parameters to a function. Declaring an array variable without a size is equivalent to declaring a pointer, what is being passed is a pointer to the array.
Using a pointer emphasizes the fact that the pointer variable will be used in a manner equivalent to an array.
