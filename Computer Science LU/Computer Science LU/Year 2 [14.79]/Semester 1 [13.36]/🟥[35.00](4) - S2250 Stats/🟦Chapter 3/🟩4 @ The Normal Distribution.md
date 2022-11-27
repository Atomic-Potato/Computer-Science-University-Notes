A random variable X with pdf
![[Pasted image 20220201200355.png | 500]]
is called normal distribution with parameter `u (mean)` and `sigma (variance)`, denoted $\large N(u, \sigma^2)$

![[Pasted image 20220201201137.png | 600]]
![[Pasted image 20221027145343.png | 300]]
# The standard normal distribution
 ![[Pasted image 20220201203002.png | 650]]

## The standard normal table
![[Pasted image 20221027135337.png | 800]]
 ![[Pasted image 20220201203818.png]]
**`NOTES:`**
- THAT IF YOU GET A z GREATER THAN 3.99 THEN THE ANSWER FOR THE PROBABILITY IS "1"
- P(y < X < z) = P(X<z) - P(X<y)
- Remember that the value youre getting from the table is the area to the left and if you want something with probability greater than some value you just reduce the result from 1
## Transformation of normal variables
This operation transforms and curve into the standard curve, and by doing so we can find the area that we want using the standard normal table instead
 ![[Pasted image 20220201204955.png | 750]]
_For example:_
$$\Large \color{} 
X \rightarrow X(30,15^{2})
$$
$$ \Large
P(X \gt 60) = P(  \frac{X-30}{15} > \frac{60-30}{15})
$$
$$\Large \color{} 
= P(Z>2)
$$

We can do the same thing but in reverse
![[Pasted image 20220201204915.png | 750]]
We dont also have to just transform to the normal, we can transform any curve to another by just transforming the first to normal and the normal to second

# The Normal Approximation to the Binomial Distribution
Video: https://youtu.be/CCqWkJ_pqNU

The normal distribution can actually be used to approximate the value of [[🟩3 @ Some usual discrete random variables#Binomial|Binomial Trials]] instead of having to repeat it over and over again
_(In questions he tells you to actually approximate the value, so if you dont see it then you probably have to just do the binomal distribution normally)_