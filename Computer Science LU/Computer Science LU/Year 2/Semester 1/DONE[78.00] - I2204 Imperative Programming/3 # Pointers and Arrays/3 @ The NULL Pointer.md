# Definition
The constant `NULL` is a special pointer value with encodes the idea of `point to nothing`. `Null` value is `0x0 (zero in hex)`
It is a runtime error to dereference a `NULL` pointer

It's a good practice to check in functions that use pointers if the value of the pointer address is NULL to `return` and stop the function from running