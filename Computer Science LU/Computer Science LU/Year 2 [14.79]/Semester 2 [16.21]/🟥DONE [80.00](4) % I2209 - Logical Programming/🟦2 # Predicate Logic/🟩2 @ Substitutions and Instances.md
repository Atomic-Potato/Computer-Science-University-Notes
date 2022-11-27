# Substitution and Instances
- A `substitution σ` is a finite set $\large \color{cyan} (V_i /t_i )$ or $\large \color{cyan} (V_i \space by \space t_i )$ where each $V_i$ is a variable, each $t_i$ is a [[🟩1 @ Predicate Logic#Terms|term]] different of $V_i$ and none of the element of this set has the same variable $V_i$ ^substitution
*For example: σ = {X/a,Y/f (g(a)),Z/g(T)}*
- Let σ be a substitution, E an expression. The expression obtained by replacing simultaneously all the occurrence of $V_i$ by $t_i$ for all i is noted $E_σ$ and called the `instance` of E. ^instance
*For example: , E = P(X,Y) ∨ Q(g(X),Z), σ = {X/f (a),Y/g(T),Z/T} then $E_σ$ = P(f (a),g(T)) ∨ Q(g(f (a)),T)*
- **Forbidden substitutions**: constant/anything, X/f(X) (variable by a function), function/anything

# Composition of substitutions
![[Pasted image 20220620181346.png | 400]]
The `composition` of θ and σ (noted σ ◦ θ) is the substitution obtained form
![[Pasted image 20220620181417.png | 400]]
![[Pasted image 20220620181431.png | 300]]

Basically you first apply the substitution theta and then you apply the substitution sigma. Note that its not commutative and its not the same the other way around.
