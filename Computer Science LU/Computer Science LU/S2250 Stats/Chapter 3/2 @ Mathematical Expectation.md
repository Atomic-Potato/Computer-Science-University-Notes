# Mean of a random variable
The mean (expected value, average) of a continuous random variable X, denoted E(X) (or u), is defined by:
$$E(X) = \int_Rxf(x)dx$$
Same goes for these (same as chapter 2 but for continuous)
![[Pasted image 20220118142243.png | 500]]

# Mean of a function of random variable
The expectation of g(X), where g is any function, is defined by:
$$E(g(x)) = \int_Rg(x)f(x)dx$$
### Linearity of E(X)
If X is a continuous random variable, with pdf f(x), then:
$$E(aX+b) =aE(X)+b$$
where a and b belong to R

# Variance
**Defining formula**
The variance of X, denoted Var(X) (or σ 2 ) is defined by
$$Var(X) = E[(X-E(X))^2]$$
For a continuous random variable X with pdf f(x):
$$Var(X) = \int_R(x-E(X))^2f(x)dx$$
**Computing formula**
The variance of a random variable X can be computed by the
formula:
$$Var(X)=E(X^2)-[E(X)]^2$$
**Properties of the variance**
If X is a continuous random variable, and a,b are real
numbers, then:
- Var(X) ≥ 0; moreover Var(X) = 0 iff X = E(X)
- Var(aX + b) = $a^2$ Var(X)

**Standard deviation**
The standard deviation of a continuous random variable X, denoted `σ`, is the square root of the variance of X, i.e
$$σ(X) =\sqrt{Var(X)}$$
It is simple to check that
$$σ(aX + b) = |a|σ(X)$$
**Moments**
The moments of order n of a random variable X are defined
by $E(X^n)$:
$$E(X^n) = \int_Rx^nf(x)dx$$
E(X) is the moment of order 1 of X

**Moment Generating Function**
The moment generating function (mgf) of a random variable X, denoted G X , is defined by:
$$G_X(s) = E(e^{sX}) = \int_Re^{sx}f(x)dx$$ 