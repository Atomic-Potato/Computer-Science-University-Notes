# Finding the cache line
Say we want to find the address of the hexadecimal `0xbe` if it was at line 0 of the cache having:
- memory address size: 8 bits
- index size: 3 bits
- offset size: 2 bits

Convert to binary
```c
b -> 1011
e -> 1110

//which lines up to
10111110
```
And idk why exactly but set the offset bits to 0  (i think relevant to an x column binary table and x here is 8)
And so it becomes
```c
10111000 // which you can convert back to hexadecimal if needed to
```