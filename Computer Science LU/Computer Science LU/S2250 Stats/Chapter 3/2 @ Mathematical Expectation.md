# Mean of a random variable
The mean (expected value, average) of a continuous random variable X, denoted E(X) (or u), is defined by:
$$\huge E(X) = \int_Rxf(x)dx$$
Same goes for these (same as chapter 2 but for continuous) `[idk what i was talking about]`
![[Pasted image 20220118142243.png | 500]]

# Mean of a function of random variable
The expectation of g(X), where g is any function, is defined by:
$$\huge E(g(x)) = \int_Rg(x)f(x)dx$$
### Linearity of E(X)
If X is a continuous random variable, with pdf f(x), then:
$$\huge E(aX+b) =aE(X)+b$$
where a and b belong to R

# Variance
**Defining formula**
The variance of X, denoted Var(X) (or σ 2 ) is defined by
$$\huge Var(X) = E[(X-E(X))^2]$$
For a continuous random variable X with pdf f(x):
$$\huge Var(X) = \int_R(x-E(X))^2f(x)dx$$
**`Computing formula`**
The variance of a random variable X can be computed by the
formula:
$$\huge Var(X)=E(X^2)-[E(X)]^2$$
**Properties of the variance**
If X is a continuous random variable, and a,b are real
numbers, then:
- Var(X) ≥ 0; moreover Var(X) = 0 iff X = E(X)
- Var(aX + b) = $a^2$ Var(X)

**Standard deviation**
The standard deviation of a continuous random variable X, denoted `σ`, is the square root of the variance of X, i.e
$$\huge σ(X) =\sqrt{Var(X)}$$
It is simple to check that
$$\huge σ(aX + b) = |a|σ(X)$$
 