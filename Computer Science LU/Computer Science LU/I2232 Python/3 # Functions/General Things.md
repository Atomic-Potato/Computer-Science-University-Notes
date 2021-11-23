# What does the auto keyword means ?
```c
auto int num;
```
The auto keyword is not necessary but what it means is whenever we see an open brace we allocate in memory a space for the variables and once we reach a closing curly brace it means we automatically deallocate the variable from the memory instead of the programmer explicitly writing the code to do so.
# Notes
- Functions
Declaring a function is just the first line like
```c
void Function();
```
Defining a function is everything in between the brackets
`Parameters` are the variables when declaring a function while `Arguments` are the values given to a called function

Each invocation of the same function will create a new location for this new function in the memory and each one is distinct and unrelated to the other