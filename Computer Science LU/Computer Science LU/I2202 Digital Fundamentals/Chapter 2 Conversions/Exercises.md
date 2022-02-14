# EX 1
- (1)
`a-` $10^0$
`b-` $10^2$
`c-` $10^5$

- (2)
`a-` $10^1$
`b-` $10^2$
`c-` $10^4$
`d-` $10^6$

- (3)
`a-` $4*10^3 + 7*10^2 + 1*10^1$

- (4)
9999

# EX 2
- (5)
`a-` $11 = 1*2^1 + 1*2^0 = 2+1 = 3$
`f-` $11101 = 1*2^4 + 1*2^3 + 1*2^2 + 0*2^1 + 1*2^0= 16+8+4+1 = 29$

- (6)
same as above

- (7)
`b-` $101010.01 = 1*2^5 + 0*2^4 +1*2^3 +0*2^2 +1*2^1+0*2^0 + 0*2^{-1} + 1*2^{-2} = 42.25$

- (8)
For all of them its actually $2^n-1$
`a-` $2^2-1=3$ 

- (9)
**`IMPORTANT`**
If you look at [[Chapter 2 Conversions#For Binary]] you can see that to find how many binary digits a decimal number requires you need to find find the ==$2^n-1$== that is the smallest and contains the decimal number, `n is the number of bits required`

- (10)
`e-`
```c
64 32 8 4 2 1
1  0  0 0 0 0 //64
1  0  0 0 0 1 //65
1  0  0 0 1 0 //66
1  0  0 0 1 1 //65
1  0  0 1 0 0 //66
1  0  0 1 0 1 //67
1  0  0 1 1 0 //68
//..and so on till 75
```
**`IMPORTANT`**
This pattern also applies for other bases, like base 3
```c
00
01
02
10
11
12
```
# EX 3
- (11)
`a-`
```c
10
32 8 4 2 1
0  1 0 1 0
```

- (12)
`a-`
```
0.32
0.5 0.25 0.125 0.0625 ....
0   1    0     1      ....
```

- (13)
you already know how

- (14)
`c-`
```c
0.9028 x 2 carry = 1
0.8056 x 2 carry = 1
....
0.11...
```

# EX 4
- (15)
`a` 100
`b` 100
`e` 1110
`f` 11000

- (16)
`e` 0011
`f` 00011

- (17)
`f` 10110110

- (18)
`b` 10.1
`c` 11

# Ex 5
- (19)
`e`  0001010

- (20)
`h` 11000011

# Ex 6
- (21 22 23)
`d` -123
binary = 01111011 (123)
Signed magnitude = 101111011 (-123)
1's c = 10000100
2's c = 10000101
`Notice how the sign bit is 1 (negative) in 2's and 1's`

- (21)
if the MSB directly convert to decimal, other wise remove the MSB => convert => add negative sign

- (22)
if MSB = 0, convert directly
otherwise do 1's complement and convert then add negative sign

- (23)
same as 22 but with 2's c

- (27)
`b` 1 10001010 10000011000...0 (until we have 23 bits in the last part)
hex = C5418000

- (28)
`a` $-1^1 * 1.01001001110001 * 2^{129-127}$
= -101.001001110001

# EX 7
- (29)
`d` 
110 = 01101110 | 2's = 10010010
84 = 01010100 | 2's = 10101100
2's sum = 00111110 (carry is garbage) (if we were doing it on 9 bits it would be fine)
 
 - (33)
 **If both numbers are positve / negative then no need to convert to 2's complement in the end, else then convert the negative number to 2's complement and multiply**
 result 11000110110 =>2's c=>  00111001010 WRONG, to make it signed we add 1 as the MSB 100111001010
 
 - (34)
 same idea as above but with division 
 
 # Ex 8
 - (35)
you can directly do it from base 8 to base 2

- (36)
you can directly do it from base 2 to base 8 by doing groups of 4 bits

- (37)
EB, E is 16^1, B is 16^0
14 x 16 + 11 x 1 = the result in decimal

- (38)
the usual, divide by the base number

- (39)
FF + BB, convert to base 10, add then convert back to hexa
187 + 255 = 442 = 1BA

- (40)
![[ex 40.jpg | 300]]

# Ex 9
Same as 8

# Ex 10
- 45
convert each decimal digit to a 4 digit binary  
125 = 0001 0010 0101

 - 47
 same as 45
 
 - 49 
 j = 6662
 
 - 51
 group each four digits from each number and add them
 h = 1100 0110 1001 != 1269 = 561+708
 Here the column `1100` is incorrect so we add to `6` = `0010`
 and so the correct result will be `0001 0010 0110 1001`
 <label class="ob-comment" title="" style="">  <input type="checkbox"> <span style=""> This is only applied when the sum of the column is greater than 9 or we get an extra carry that doesnt fit in the column </span>When do we apply this rule?</label>

 - 52
  h = 0100 0101 1010

  # Ex 11
  - 53
  Gray code avoids this problem since `1111` in gray code is `1000` and therefore theres only one bit change between `1000` and `0000`

  - 54
  c = 1000110011001

  - 55
  c =  1000110011001 (in gray code) = 1111011101110

  `In the rest of the exercises refer to an ASCCII table and convert normally to get what you want, just not in ex 56, you take each digit on its own and convert it, because remember these are characters`

  # Ex 12
  - 61 
  a, no, b, yes, c, no `The actual info is all the bits without the MSB, the parity bit`

  - 62
  a yes, b no, c yes

  - 63
  a add 1 | b add 0 | c add 1

  - 64
  cant really bother lol