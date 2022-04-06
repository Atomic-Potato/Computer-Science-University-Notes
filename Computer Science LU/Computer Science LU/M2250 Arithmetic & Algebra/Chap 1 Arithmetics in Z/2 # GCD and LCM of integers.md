# Definitions
**Definition 1** 
Let a,b,d are three non-zero integers. We say that d is the `greatest common divisor` of a and b (denoted by GCD or `d = a ∧ b`) if:
	1) `d | a` and `d | b` (so d is common divisor).
	2) if c is an integer such that `c | a` and `c | b` then,` c | d` (so d is the greatest divisor).

**Definition 2**
1) Two integers a,b are said to be `relatively prime (or coprime)` if a ∧ b = 1.
2) More generally, a set of integers a 1 ,...,a n are coprime if a 1 ∧a 2 ∧...∧a n = 1. and mutually coprime if a i ∧ a j = 1,∀i 6= j.

**Definition 3**
m is LCM of and b if:
1) a | m and b | m (so m is common multiple).
2) if m' is an integer such that a | m' and b | m' then, m | m'
`Note that a and b should be >= 3`
Notation: ==(m = a 1 ∨ a 2 ∨ ... ∨ a n ).==

The equation:
$$LCM = \frac{|a.b|}{GCD}$$

**Definition 4**
Let a and b are two integers in Z. We say that `a is congruent to b modulo n` if `n divides a − b`. That is, there exists `k ∈ Z such that a = b + kn`. When a,b are congruent modulo n, we write `a ≡ b (mod n)` or simply` a ≡ b(n)`.
- a and b have the same remainder when divided by n
- **`Important`**
To find the remainder of the division of x by n we need to find the `0 <= r <= n-1` such that `x ≡ r(n)`
- The congruence relation is symmetric, reflexive and transitive
# Propositions
**Prop 1**
Let a,b,q,r are integers such that a = bq + r then, `a ∧ b = b ∧ r.`

**Prop 2**
Let a,b are two integers divisible by d and λ ∈ N* then,
1) a ∧ b = d ⇔ a/d ∧ b/d = 1.
2) λa ∧ λb = λ(a ∧ b).

**Prop 3 `IMPORTANT`**
Let a,b,c are three non-zero integers then the following statements hold.
1) If a | c, b | c and a ∧ b = 1 then ab | c.
2) If a | bc and a ∧ b = 1 then a | c.
3) If a ∧ b = 1 and a ∧ c = 1 then a ∧ bc = 1.
4) If p is a prime number then p | a or p ∧ a = 1.
5) If p is a prime number such that p | ab then, p | a or p | b.
   


**Prop 4**
Let a,b are non-zero positive integers and m = a ∨ b then,
1) If a ∧ b = 1 then, `m = ab`.
2) For every λ > 0, we have `λa ∨ λb = λm.`

**Prop 5**
n ≥ 2 and a 1 ,...,a n are integers. Then,
$$a_1 ∨ ... ∨ a_n = m ⇔ \frac{m}{a_1} ∧ ... ∧ \frac{m}{a_n} = 1$$

**Prop 6**
Let a,b ∈ Z. Then, a and b are congruent modulo n, if and only if, they have the same remainder of division by n.

**Prop 7**
Let a,b ∈ Z such that a ≡ b (mod n) `(means a-b = kn)` then, ∀t ∈ Z we have,
1) a + t ≡ b + t (mod n).
2) at ≡ bt (mod n). `if n ∧ t = 1`
3) a + tn ≡ b (mod n).

**Prop 8**
Let a,b,c,d ∈ Z such that a ≡ b (mod n) `(a-b = kn)` and c ≡ d (mod n) `(c-d = k'n)` then,
1) a + c ≡ b + d (mod n).
2) a ≡ b (mod n) ⇔ a − b ≡ 0 (mod n).
3) ac ≡ bd (mod n)
4) a s ≡ b s (mod n), ∀s ∈ N*. 

**Prop 9**
Let a,b ∈ Z. α ∈ N*. If αa ≡ αb (mod n) and α ∧ n = 1 then, a ≡ b (mod n).

**Prop 10 `IMPORTANT`**
(a bar is the equivalence class of a, i think it means all the number that satisfy the relation xRy ⇔ x ≡ y (mod n))
The relation congruency modulo n is an equivalence relation on Z. In addi-
tion, for every a,b ∈ Z we have,
1) $\overline a = nZ + a.$
Proof:
$$a = {α ∈ Z/ : α ≡ a (mod n)} = {α ∈ Z/ : α = kn + a,k ∈ Z} = {kn + a,k ∈ Z} = nZ + a.$$
3) $\overline {a + b} = \overline a + \overline b.$
4) $\overline{a.b} = \overline a . \overline b.$
5) $\overline n = \overline 0.$ **`OMEGA IMPORATANT`**

# Theorems
**Theorem 1**
For large numbers we have the following algorithm to find the ==GCD==
- first we divide a and b (a/b, a>b)
- and we keep the quotient and the remainder
- now we will have the result `a = b*quotien + remainder`
- repeat the process but with b and the remainder
- keep doing this until you reach a remainder of 0
The remainder that is right before the remainder 0 is the the GCD ==d = r_(n−1)==

- **corollary 1**
The following statements are equivalent:
i) d = a ∧ b.
ii) d|a and d|b and there exist α,β ∈ Z such that d = αa + βb.
<label class="ob-comment" title="" style="">  <input type="checkbox"> <span style=""> if we have the  d = αa + βb alone, this doesnt mean it implies d = a ∧ b</span>Note</label>



- **corollary 2 `IMPORTANT`**
a ∧ b = 1, if and only if, there exist α,β ∈ Z such that `αa + βb = 1`. ==(Bezout’s identity)==
`Importnant notes`
Note that one of alpha or beta should be negative and the other positive. And any combination of these integers (a,b,alpha,beta) gives us 1. Example
a ∧ alpha = 1
alpha ∧ beta = 1
b ∧  alpha = 1 
etc.

How to get the quotient and the remainder:
- Quotient:
	- Just divide the numbers and your integer value of the result will be the quotient
- Remainder:
	- Subtract the divisor from the dividend repeatedly until your result is less than the divisor, this will be your remainder
	  Or you can use the equation `quotient*divisor + y = dividend` where y will be the remainder, best used when the divisor is greater than the dividend   


**Theorem 2**
Let a,b are two non-zero integers (we can assume that a,b > 0 without losing
generality) then `(a ∧ b)(a ∨ b) = ab`.

**Theorem 3**
In N, each integer n ≥ 2 can be written, in a unique way, as
$$n = p^{e_1}_1 ... p^{e_r}_r$$
where $p_1,...,p_r$ are distinct primes and $e_1 ,...,e_r$ are positive integers. This way is called prime-power factorization. In addition, up to ±1, the theorem is true over Z.
- **corollary 1**
Let a,b are two non-zero positive integers, then a∧b = 1, if and only if, there
is no common prime number dividing both a and b.

**Theorem 4**
Modulo n, we have exactly n classes 0,1,...,n − 1. The set of classes is denoted by
$$Z/nZ = \{\overline{0},\overline{1},...,\overline{n − 1}\}.$$

# Interpretation `(Important)`
![[interpretation 1.jpg | 600]]
![[interpretation 2.jpg | 600]]