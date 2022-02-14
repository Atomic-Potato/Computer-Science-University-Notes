# The inverter
The inverter performs the Boolean `NOT` operation. When the input is **LOW (0)**, the output is **HIGH (1)**, and vice versa.
![[inverter representation.jpg | 150]]
![[inverter representation 2.jpg | 150]]
The `NOT` operation (complement) is shown with an overbar. Thus, the Boolean expression for an inverter is
$$X = \overline{A}$$

A group of inverters can be used to form the 1's complement of a binary number
![[1's complement with inverters.jpg]]

# The AND gate
The `AND` gate produces a `HIGH` output when all inputs are `HIGHT`, otherwise the output is `LOW`.
![[AND gate representation.jpg]]
We denote the `AND` operation like so:
`X = A.B` or `X = AB`

# The OR gate
The `OR` gate produces a `HIGH` output if any input is `HIGH`, and if all inputs are `LOW`, the output is `LOW`
![[Or gate representation.jpg]]
We denote the `OR` operation with `+` like so:
`X = A+B`

# The NAND gate
The `NAND` gate produces `LOW` output when all inputs are `HIGH`, else the output is `HIGH`
![[NAND gate representation.jpg]]
==The smoll bubble makes the 0 a 1 and the 1 a 0==

We denote the `NAND` operation as a dot between the variables and an overbar covering them:
$X = \overline{A.B} \space or \space X = \overline{AB}$

# The NOR gate
The `NOR` gate produces a `LOW` output if any input is `HIGHT` and if all inputs are `HIGH` the output is `LOW`

The `NOR` operation is denoted with a `+` and an overline
$$X\space = \space \overline{A+B}$$

# The XOR gate
The `XOR` gate produces a `HIGH` output only when both inputs are opposite
![[XOR gate.jpg]]
We denote the `XOR` with an encircled `+`:
$$X = \overline{A}B+A\overline{B}$$
$$or$$
$$X \space = \space A (+) B$$

# The XNOR gate
The `XNOR` gate produces `HIGH` output only when both inputs are the same logic level
![[XNOR gate.jpg]]
Denoted:
$$X \space = \space \overline{AB}+AB$$
$$or$$
$$X \space = \space A(.)B$$