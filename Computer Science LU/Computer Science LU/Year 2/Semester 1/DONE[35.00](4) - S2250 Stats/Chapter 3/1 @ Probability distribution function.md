# Definition
A continuous random variable is a variable whose values are within an interval (a,b) with a,b belong to $\mathbb{R} \cup { \infty }$ 

# Probability Density
The probability distribution function (pdf), or density, f(x) of a continuous random variable X satisfy the following properties:
- f(x) >= 0 for all x in (a,b)
- $\int_{\mathbb{R}} f(x)dx = 1$
- P(X belong A) = $\int_{\mathbb{A}} f(x)dx$, for every interval A belong $\mathbb{R}$ 
smoll notation note:
![[Pasted image 20220320185102.png]]

# Cumulative distribution function
The cumulative distribution function `(CDF)` of a random variable X is defined by:
$$F_x(x) = P(X<=x)=\int_{\infty}^xf(t)dt$$
The PDF and the CDF of a random continuous variable X are related by the formula:
$$f(x)=F_x'(x)$$
`Note:`
$\sum$ and $\int$ are the same though the first is for discrete summation while the other is for continuous summation
