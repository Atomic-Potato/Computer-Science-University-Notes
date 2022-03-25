# Bernoulli
Its a variable is a variable that takes exactly 2 values, `1 (success) and 0 (failure)`
The PDF of a benoulli random variable X with a parameter p, denoted `b(p)`, 
$$\huge f(x) = (1-p)^{1-x}p^x$$
where x belongs to [0,1]
and `E(X) = p and Var(X) = p(1-p) = p - p^2`

# Binomial
A binomial random variable is a repetition of n independent Bernoulli trials, with the same probability of success p. If X denotes the number of success among the n trials, then X is Binomial, with parameter n (nb of trials) and p(prob of success), denoted `b(n, p)`.
==The bernoulli is a special case with n=1==

Its PDF is given by:
$$\huge f(x) = C_n^x(1-p)^{n-x}p^x$$
x belongs to {0...n}
`E(X) = np`
**`Important calculation Note`**
$$\huge kC_n^k = nC_{k-1}^{n-1}$$
`V(X) = np(1-p)`

# Geometric
A Geometric random variable is a repetition of independent Bernoulli trials, with the same probability of success p, until one success occurs. If X denotes the number of trials needed, then X is geometric with parameter p, denoted `G(p)`.
Its PDF is given by:
$$\huge f(x) = (1-p)^{x-1}p$$
where x belongs to {1,2....,n,....}
<label class="ob-comment" title="" style="">  <input type="checkbox"> <span style=""> P(X=x) = f(x) and the PDF is the values that can be taken by x</span>Note </label>

`E(X)` = $\frac{1}{p}$
`V(X)` = $\frac{1-p}{p^2}$

# Negative Binomial
A Negative Binomial random variable is a repetition is a repetition of independent Bernoulli trials, with the same probability of success p, until r success occurs. If X denotes the number of trials needed, then X is negative binomial with parameters r and p, denoted `NB(r, p)`.
Its PDF is given by:
$$\huge f(x) = C^{r-1}_{x-1}(1-p)^{x-r}p^r$$
where x belongs to {r, r+1, r+2, ....}
`E(X)` = $\frac{r}{p}$
`Var(X)` = $r.\frac{1-p}{p^2}$

# The Poisson Distribution
It is used on a random variable that counts the number of occurrences of an event `lambda` during a unit of measurement such as time or an area `k`.

A random variable X with PDF:
$$\huge P(X=k) = e^{-\lambda}\frac{\lambda ^k}{k!}$$
where k = 0,1,2,3... and the `rate` $\lambda > 0$
is called Poisson distribution with parameter $\lambda$ denoted $P(\lambda)$

`E(X)` = $\lambda$
`V(X)` = $\lambda$

==Calculation Note==
![[calculation note.jpg | 200]]

