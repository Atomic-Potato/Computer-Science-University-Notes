We can declare initialized strings using char pointers like so:
```c
char *name = "Potato"; //array of 7 chars
// the '\0' is included by itself
//You can use
static const char *name = "Potato";
//if the string are constant
```
The pointer of normal arrays is constant, however the array made using a pointer is variable

# Array of char VS. Char Pointer
![[arrays vs pointers.jpg | 700]]

# Which to use ?
- **declare an array of char:**
`char s[size]` inside function bodies when you need to edit the element of s: read from keyboard and fill, or concatenate, or copy from another string, or append etc.
- **declare a pointer to char:**
`char* s` as function parameters, and when declaring constant strings (in this latter case you should directly initialize).

# Long strings
We can split long strings across lines when initializing 
```c
static const char *str = "big ass string"
						"that spans on on multiple"
						"lines";
```

# string.h
![[string library.png | 600]]

# `Making a string without using array notation`
```c
#define SIZE 1000

char* string = (char*)malloc(SIZE * sizeof(char))
```