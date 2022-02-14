We have 2 special pointer operators
- addressing or referencing operator `&`
- dereference operator `*`

# & Operator
`&` is a unary operator that returns the memory address of its operand

# * Operator
- Applied to a pointer m of base type T
- The unary operator `*` gives the value of the object of type T pointed by m
- `*` is the complement of `&`

==If you make a pointer point to a type different than its own then it will take the binary value of the part that is compatible with the pointer type and if we try to give the pointer value to a variable of the same type we were pointing to, it will have the same binary value in the first part and some garbage binary values for the rest==

# Pointer Assignment
```c++
int *p1, *p2;
// the star is necessary for each pointer

//if you want to print the address of variable
// slash the value of the pointer, you use %p

printf("%p", p1);
```

# Pointer Arithmetic
We can `increment` a pointer variable but for example if we increment the address of an int which is 204 by 1 it will be 208 because an int is 4 bytes, you can check the size of a variable by using `sizeof(variable_type)`
The same is for `decremnting`

You may `add` or `subtract` integers `to` or `from` pointers
```c
p1 = p1 + 12
```

You may subtract one pointer from another in order to find the number of objects of their base type that separate the two
```c
n = p1-p2
```

==All other arithmetic operations are prohibited and you can only add or subtract with ints==

# Pointer comparisons
You can compare pointers in if statements 