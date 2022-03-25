# Mean of a function of couple of random variable
Let (X, Y) be a couple of random variables with pdf f(x, y).
The `mean` of g(X, Y) denoted `E(g(X, Y))` is defined by:
$$\huge E(g(X, Y)) = \int_R\int_Rg(x,y)f(x,y)dA$$
if X and Y are continuous, and
$$\huge E(g(X, Y)) = \sum_x\sum_yg(x,y)f(x,y)$$
if X and Y are discrete.

# Covariance
## Defining formula
Let (X,Y) be a couple of random variables with joint pdf f(x,y). The `covariance` of X and Y, denoted `Cov(X,Y)`, is
defined by:
$$\huge Cov(X,Y) = E[(X − E(X))(Y − E(Y)]$$
## Computing formula
The covariance of X and Y can be computed by the following formula:
$$\huge Cov(X,Y) = E(XY) − E(X)E(Y)$$
## Properties
- Cov(X,X) = Var(X)
- Cov(aX,bY + c) = abCov(X,Y)
- If two variables X and Y are independent then Cov(X,Y) = 0 **`BUT NOT VICE VERSA DUMBASS !`**

# Coefficient of correlation
The correlation coefficient is the specific measure that quantifies **the strength of the linear relationship between two variables in a correlation analysis**. **`ITS ALWAYS BETWEEN 0 AND 1`**

Let (X,Y) be a couple of random variables with joint pdf f(x,y). The `correlation coefficient` of X and Y, denoted
`ρ(X,Y)`, is defined by:
$$\huge ρ(X,Y)= \frac{Cov(X,Y)}{σ(X)σ(Y)}$$
## Properties
- ρ(X,X) = 1
- ρ(X,Y) = ρ(Y,X)
- ρ(aX,bY) =$\frac{ab}{|ab|} ρ(X,Y)$
