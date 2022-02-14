# Weighted number system
### For Decimal Numbers
`I still dont get what this is for`
The position of each digit in a weighted number system is assigned a weight based on the `base` or `radix` of the system .
The radix of decimal numbers is `10`, because only ten symbols are used to represent any number.
The column weights of decimal numbers are powers of 10 that increase from right to left beginning with 10^0 = 1. `... 10^3 10^2 10^1 10^0.`
For fractional decimal numbers, the column weights are negative powers of 10 that decrease from left to right.  `10^1 10^0.10^-1 10^-2 ...`

Decimal numbers can be expressed as the sum of the produst of each digit times the column value for that digit. Example:
```c
420.69 = 4 * 10^3 + 2 * 10^2 + 0 * 10 + 6 * 10^-1 + 9 * 10^-2
```
### For Binary
The column weights of binary nums are powers of 2 that increase from right to left beginning with `2^0 = 1`.

**How to count in binary**
Notice the columns
![[binary conversion pattern.jpg | 200]]

**How to convert from binary to decimal**
Take the number 11 from the picture above
```python
11 = 1 * 2^4 + 0 * 2^3 + 1 * 2^1 + 1 * 2^0
```


**How to convert from binary to decimal (weight number way)**
take for example the number `100101.01`
```c
2^5  2^4  2^3  2^2  2^1  2^0  .  2^-1  2^-2
32   16   8    4    2    1    .  1/2   1/4
1    0    0    1    0    1    .  0     1
32             4         1    .        1/4   = 32 + 4 + 1 + 1/4 = 37.25
// i shouldve screenshoted this, im such a dumbass
```


**From decimal to binary using weighted numbers (sum of weights method)**
First write the column weights until the last one is larger or equal than the one you want
Then you take the first one that is smaller than it and reduce it from the decimal number
repeat the process with the new number until reached the last weight.
For the ones not used we put 0 and for the ones used we put 1.
An example for the number 49:
![[coverting from decimal to binary with weighted numbers.jpg | 250]]

**How to convert fractional decimals to binary (inaccurate)**
By repeatedly multiplying the fractional results by 2. Keep the fractional part on the side and order it from the least significant bit (theres no stopping condition)
Example on 0.188
![[converting fractional parts to binary inaccurate.jpg | 350]]

**Converting decimal to any base**
By repeatedly dividing of the base number and keeping the remainder on the side and ordering it from the `MSB = the last remainder of the last division ` to `LSB = the first remainder of the first division`  (you should reach 0 at last)

# Operations
### The rules of binary addition
![[the rules of binary addition.jpg]]
When an input `carry = 1` due to a previous result, the rules are:
![[binary sum when carry is 0.jpg]]
example:
![[example of binary sum.jpg | 300]]

### rules of binary subtraction
![[rules of binary subtraction.jpg]]
example
![[example of binary subtraction.jpg | 300]]

A better way
https://youtu.be/C5EkxfNEMjE
Brief explanation:
1 - 0 = 1; 0 - 0 = 1 (these are the basic rules)

but say we have:
```
1 0
-
   1
```
Then we borrow 1 from  the first 1 in `1 0` and we get `0 2`
and so we get 0 2 - 1 = 0 1

say we have:
1 0 0
minus
      1
then we borrow 1 from the first 1 in `1 0 0` and we get `0 2 0` and then we borrow 1 from 2 then we get `0 1 2`
and so we do
0 1 2
minus
0 0 1 
equals
0 1 1

### Rules of binary multiplication
1 x 0 = 0
0 x 0 = 0
1 x 1 = 1

it is basically a dot product
![[binary multiplication.jpg | 200]]
you just multiply each digit of one of the number with all of the other number's digits
you shift the result one cell to the left for each digit multiplication
and add in all the results
`Note:`  **If both numbers are positve / negative then no need to convert to 2's complement in the end, else then convert the negative number to 2's complement and multiply**

### Binary division
too hungry to explain
https://youtu.be/VKemv9u40gc
==Just note that if you reach the end and you still have a remainder, you add .1 to the quotient and add 0 to the end of the remainder and continue, you can do it as many times as you want when this happens==

# Complements
**1's complement**
To form 1's complement, change all 1s to 0s and vice versa
**2's complement**
It is found by adding 1 to the `LSB` of 1's complement.
An easier way is to to start at the `LSB` and if its a zero move on to the next one until you reach the first `1` then you can swap the rest of the binary digits normally

# Signed Binary numbers
Positive numbers are stored in their *true* form (with 0 for the sign bit) and negative numbers are stored in *complement* form (with a 1 for the sign bit) `Note that this bit is the MSB`
Negative numbers are simply the 2's compliment of the positive number
Example
58 = `0`*0111010*
-58 = `1`*1000110*

**how can we read 11000110 for example**
We use the weighted number system and by assigning to each column a wait from `2^0 for the LSB to 2^n-1 for the MSB-1` and for the MSB which is the signed number we put `-2^n`
Then we add the MSB to the weights that represent `1s`
```c
-128 64 32 16 8 4 2 1
1    1  0  0  0 1 1 0
-128 + 64 + 4 + 2 = -58
```
This also works for positive binaries

# single-precision-floating-point-numbers
Floating point numbers are capable to display very large or small numbers in a scientific notation like so:
![[floating point numbers.jpg | 500]]
We usually convert the result to hexadecimal

**Arithmetic operations**
**`Addition`** Add the 2 signed binary numbers normally and discard any final carries, the result will be in signed form

Becareful of overflow:
![[overflow.jpg | 500]]

**`Subtraction`** we 2's complement of the number we are reducing and we apply addition 

# Hexadecimal Numbers 
![[hexadecimal numbers.jpg | 250]]

**Converting from binary to hexadecimal**
Example:
```c
8 4 2 1
1 0 0 1
8 + 1 = 9 = 9 in hexadecimal
```
If you have multiple 4 bit binary groups, you group the result in the same order of the binary numbers

**Hexadecimal weights**
The column weights are power of 16, which increase from right to left
```
... 16^2 16^1 16^0
... 256  16   1
```
**How to use weights to express it in decimal**
![[hexadecimal weights to decimal.jpg | 300]]

**Addition (using an example)**
```c
ADD
+
DAD

//we start adding from right to left
D + D = 26
26 = 1*16 + x // 1 is the carry, 16 is the base and x is the result
x = 10 = A

1 + D + A = 24
24 = 1*16 + x
x = 8

1 + A + D = 24 ==> x = 8
// we will still have a carry of 1 which we put at the left
result = 188A
```

# Octal numbers
![[octal numbers.jpg | 250]]

**Binary ==> octal**
same as hexadecimal but with only 3 bits

**Weights of octal and conversion to decimal**
![[weights of octal.jpg | 300]]

**Addition of octals**
same as hexadecimal but with 8 instead of 16

**Subtraction of octals**
```
5 1 1 
-
0 3 3

1 - 3 // 1 is less than 3 so we borrow from the number next to 1 and so we have
5 0 (8+1)
-
0 3 3
//and so
9 - 3 = 6

0 - 3
// borrow from 5
8 + 0 - 3 = 5

4 - 0 = 4

and the final result is 456
```
# BCD
![[BCD.jpg | 250]]
Binary coded decimal is a weighted code that is commonly used in digital system when its necessary to show decimal numbers.
Notice that the BCD represents each digit in a decimal number, in its binary and doesnt go above 9

**weights of BCD**
![[weights of bcd.jpg | 600]]

# Gray code
![[Gray code.jpg | 250]]

Gray code is an `unweighted` code that has a single bit change between one code word and the next in a sequence.

**converting binary to gray code**
take the binary `1010` we just add each 2 digits together
```cpp
0110 = 0101 in gray code
//We start from the MSB
0   = 0
0+1 = 1
1+1 = 0
1+0 = 1
//carry is ignored 
```

**Gray ==> binary**
converting 1100
![[gray to binary.jpg | 150]]

# Parity method
Its a method of error detection for simple transmission errors involving 1 bit (or an odd number of bits). A parity bit is an extra bit attached to a group of bits to force the number of 1's to be either even or odd.
![[example of parity.jpg | 500]]

# Hamming Code
The hamming code is used to detect the position of the 1 bit change error when the info is being sent and fix it without the need to send it again.

## How to generating a hamming code

We use the following formula on the bit number we got given
$$2^p >= d + p + 1$$
Where `d = number of bits` and `p = number of parity bits`
We put the d in the equation and start adjusting p so that the formula would be true

Once we found p we use $2^x$  to find the position of each parity in the hamming code.

We make cells for position where `the number of cells = p + d`
and we number each cell with 2 types of numbers
from `1 to p+d` and from `1 in binary to p+d in binary`

Now for each parity bit we use $2^x$ , `with x being the number of the bit we're find its position`, and we place the parity bit in the cell which equals the result of $2^x$ .
And in the rest of the cells we place each `d1 to dn` and under each d we put its corresponding bit given in the bit number

**If we are looking for even parity hamming code:**
- we start with the first parity bit, we check the its binary number and we see the position of the 1 in that number
- now the parity bit is responsible for all the normal bits that has 1 in the same column of the parity number in the bits number
- if the number of 1's, in the group that the parity is responsible of, is even we give the parity number a value of 0, otherwise 1

**If we are looking for add parity hamming code:**
- same as above but with odd numbers in the last step

## How to find the position of an incorrect bit in a hamming code
**If even parity:**
- we start with each parity group including the parity number digit
- we check if the ones are even, if so then we assign 1 to the LSB to a new binary number, else 0
- repeat the process with the other parity numbers (dont replace the LSB, just add them afterwards in order)
- the resulting number is the position of the error bot