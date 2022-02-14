```
- Take the set Z/8Z = {0,1,2,3,4,5,6,7} (theres a bar over them), this set is equal to {0,1,2,3,4,-3,-2,-1}
- x is invertible if there exists y such that x*y = neutral element of the set
- The ends of a set of a modal class Z/nZ are always invertible with their y being themsels, so they are bar(1) and bar(n-1)
- If n is prime then all of the modal classes are invertible except bar(0)
```
# EX 2
1) If p <=n then p|n!  and so we get that:
- p |n!+1
- p|n!
and so p | (n!+1 - n!) = p|1 => p = 1, Impossible and so p > n

2) Suppose that the set of prime numbers $\omega \{ p_1 ... p_s\}$ is finite with $p_s$ the max prime number
Consider $g = p_s! + 1$, Since g is an integer then there exists p prime such that p | g => $p|p_s!+1$ => $p > p_s$ contradiction 

# EX 5
2) let x = (5n - 3 ) and y = (2n +5)
let d be the GCD of x and y, then d |x and d | y
=> d | (5n-3) and d | 2n+5
=>d | (2x - 5y) => d | -31
=> d = 1 or d = 31
if d = 1 then LCM = xy
if d = 31 then LCM = $\frac {x*y}{31}$

3) x and y and z = $p^2p^3$
x or y or z = $p^4q^5r^2$

5) same as (2) but you multiply $2^n-1$ by 2^3 and so you get $(y - 2^3x)$

4)  315 and 180 and 400 and 640 
let a = 315 and 180 = 1260
let x = 400 and 640 = 3600
then $a \space or \space x = \frac{1260*3600}{a \space and \space x} = \frac{1260*3600}{80}$

# Ex 8
4) $x = 7^{2n}-2*7^4+1$
3 | x <=> x $\cong$ 0(3)
mod 3: $x \cong 1^{2n}-2*1^n+1 \space [7\cong 1(3)]$
=> $x \cong 0(3)$ => 3 | x
`Note: show 20 | y
we have to prove:
4 | y and 5 | y, since 4 ^ 5 = 1
=> 20 | y`

# Ex 11
1) Suppose there exists $\alpha , \beta$ belong to Z such that:
$\alpha^{2n}-2 = 3\beta$ =>mod3=> $\alpha^{2n}-2\cong0(3)$
=> $\alpha{2n}\cong2(3)$
=> $\overline{\alpha}^{2n} = \overline{2}$ => $\overline{2}$ is square in Z/3Z, impossible
because Z/3Z contains only $\overline{0} \space and \space \overline{1}$

`EXAMPLE on the squares of Z/7Z`
$\overline{1}^2 = \overline{1}$
$\overline{2}^2 = \overline{4}$
$\overline{3}^2 = \overline{2}$
$\overline{4}^2 = \overline{-3}^2 = \overline{2}$
$\overline{5}^2 = \overline{-2}^2 = \overline{4}$
$\overline{6}^2 = \overline{-1}^2 = \overline{1}$
so is $\overline{5}x^2+\overline{4}=\overline{0}$ in Z/7Z
![[Pasted image 20220103154806.png | 300]]

2) ![[Pasted image 20220103154946.png | 300]]

# Ex 13
Note in here we always take the one with the smaller coefficient cuz its easier
![[Pasted image 20220103155232.png | 300]]
here we tried taking the larger coefficient
![[Pasted image 20220103155418.png |300]]
