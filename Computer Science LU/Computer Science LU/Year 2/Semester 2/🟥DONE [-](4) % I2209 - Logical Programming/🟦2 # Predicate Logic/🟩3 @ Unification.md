In this section we will try to use the [[🟩4 @ Resolution Principle| resolution principle]] with Predicate Logic. To get the idea started:

- Let C 1 = P(X) ∨ Q(a,X) and C 2 = ¬P(g(Y)) ∨ R(Y,b)
Can we say that literals P and ¬P are complementary?
Can we define a resolvant?
- If [X/g(a)] and [Y/a] we obtain:
	- $C_1'$ = P(g(a)) ∨ Q(a,g(a)) and $C_2'$ = ¬P(g(a)) ∨ R(a,b)
	- $C_1'$ and $C_2'$ have the resolvant C = Q(a,g(a)) ∨ R(a,b)
We can find other instance of C 1 and C 2 : [X/g(g(b))] and [Y/g(b)]
But all the resolvant obtained are instances of C

So now or objective is to find a `most general unifier (MGU)`. 
`Unification` is the process that consists of finding the affectations of variables in order to return symbolically identical expressions. ^unification