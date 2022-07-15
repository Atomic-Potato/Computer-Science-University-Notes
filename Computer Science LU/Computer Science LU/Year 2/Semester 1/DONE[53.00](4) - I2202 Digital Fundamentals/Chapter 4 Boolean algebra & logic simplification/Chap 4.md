# Boolean Addition
![[Boolean addition.jpg | 600]]

# Boolean Multiplication
![[boolean multiplication.jpg | 600]]

# Commutative laws
It means that if you put add bools or multiply them in any order you'll get the same result

# Associative laws
When `OR`ing it will be the same result
$$A+(B+C) \space = \space (A+B)+C$$
And when `AND`ing you'll have the same result
$$A(BC) \space = \space (AB)C$$

# Distributive Law
You can factor bools just like in normal algebra
$$AB + AC \space = \space A(B+C)$$
![[distrivutive law.jpg]]

# Rules of Boolean Algebra
![[Rules of boolean algebra.jpg | 500]]

# DeMorgan's 1st Theorem
The complement of a product of variables is equal to the sum of the complemented variables.
$$\overline{AB} \space = \space \overline{A} + \overline{B}$$
![[demorgans theorem.jpg]]

# DeMorgan's 2nd Theorem
$$\overline{A+B} \space = \space \overline{A}.\overline{B}$$
![[demorgans 2nd theorem.jpg]]

# SOP and POS forms
- `sum-of-products (SOP):`
$$AB+CB \space , \space \overline{A}CB + \overline{C}E$$
- `product of sums (POS):`
$$(A+B)(\overline{A}+B)$$

# SOP standard form
![[SOP.jpg | 600]]

# POS standard form
![[POS standard.jpg | 600]]


# Conversion from `SOP` to `POS` and vice versa
if you got an equation of either type (`or even none`), all what you have to is create the truth table of the equation
- And then the `results that are 0`, will be the `POS`, and the `results that are 1` will be the `SOP`
- Now in each case, if character binary value is 0 its the bar of the character and if 1, then just the normal character ($A:0 \implies \bar{A}, \space A:1 \implies A$)
- For POS, for each character in the case, you add the characters together, and then multiply each case to get the final equation
- For SOP, for each character in the case, you multiply the characters together, and then add each case to get the final equation
# Karnaugh Maps
[Youtube Link](https://youtu.be/3vkMgTmieZI)
![[Grouping rules.png | 500]]
![[Karnaugh maps.jpg | 500]]
![[Karnaugh maps 2 1.jpg | 500]]
![[Karnaugh maps 3.jpg | 500]]
![[Karnaugh maps 4.jpg | 500]]
![[Karnaugh maps 5.jpg | 500]]

# `POS` Karnaugh map
It is constructed same as the `SOP` but when we fill it depending on when the result of the equation will be 0, and when we group we group the zeroes.
Also here an `0` means an `A` and a `1` means an `A bar`, because remember that you are doing it on the case that the result should be 0.
You can also extract the `SOP` from this map by just filling every other cell with `1` and group as we normally do in an `SOP` map.