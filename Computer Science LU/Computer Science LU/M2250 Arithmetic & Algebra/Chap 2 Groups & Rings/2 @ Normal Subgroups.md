# Definitions
Let G be a group and N is a subgroup of G. We denote by `Nx` and `xN`
to be where
$$Nx = \{ αx,α ∈ N\}$$
and
$$xN = \{ xα,α ∈ N\}$$
Note that these sets are not subgroups in G because, it is not necessary that
they contain the neutral element of G. 
Also N should not be an abelian group because if so then `Nx = xN`.

**`Def 1 (Normal groups)`**
Let G be a group and N a subgroup of G. Consider the following binary
relation $R_1$ defined on G by: For every x,y ∈ G,
$$xR_1 y ⇔ y ∈ Nx$$
**`Def 2 (Normal groups)`**
For every x ∈ G. The class of x modulo R 1 is called **right class of x in G or right coset of N in G** and the class of x modulo R 2 to be **left class of x in G or left coset N in G.**

**`Def 3 (Normal groups true definition)`**
A subgroup N of a group G is said to be Normal if it satisfies one statement
in  `proposition 3`. This means that N is normal in G, if and only if, the right cosets and left cosets of N in G are the same, which also means that R 1 and R 2 are the same.

# Propositions
**`Prop 1 (Normal groups)`**
Consider a group G and a subgroup N of G. For every x ∈ G, we have:
$$Nx = N ⇔ x ∈ N ⇔ xN = N$$
**`Prop 2 (Normal groups)`**
The relation $R_1$ is equivalence relation.

**`Prop 3 (Normal groups)`**
Let N be a subgroup of a group G. The following statements are equivalent:
1) xN = Nx, ∀x ∈ G.
2) xN$x^{−1}$ = N, ∀x ∈ G.
3) xN$x^{−1}$ ⊆ N, ∀x ∈ G.
4) xN ⊆ Nx, ∀x ∈ G.

The third property is used to proof if a subgroup N is  `Normal`  because its the easiest.

# Theorems
- **Theo 1 (Lagrange):**
*Let G be finite group, N is subgroup of G then, O(N) divides O(G)*

# Remarks
- **Remark 1**
The relations $R_1$ and $R_2$ can be also defined as $xR_1 y$ ⇔ $yx^{−1}$ ∈ N and
$xR_2y$ ⇔ $x^{−1}y$ ∈ N.

- **Remark 2 `(Important)`**
Since $xR_1 y ⇔ x = y$ then we have the following important statement:
$$Nx = Ny ⇔ y ∈ Nx$$
which means that, to prove Nx = Ny, it is enough to verify y ∈ Nx or simply x ∈ Ny. 
In similar manner, xN = yN ⇔ y ∈ xN, which also implies that it is enough to verify that y ∈ xN or simply x ∈ yN in order to obtain xN = yN.

- **Rem 3**
	- Since N = Ne = eN, it follows that N is right and left coset.
	- By proposition 1, the right cosets of N in G are: N and the sets Nx where
	x ∈ G − N. The same for left cosets.
	
# Notations
* **Not 1**
We denote by the class of any x ∈ G modulo R 1 to be
$$\overline x = Nx$$
and modulo R 2 to be
$$\hat{x} = xN$$
