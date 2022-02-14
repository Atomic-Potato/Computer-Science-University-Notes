# The uniform distribution
A random variable X whose density is:
$$f(x)=\frac{1}{b-a},\space a<x<b$$
is called uniform distribution over the interval (a,b), denoted U(a,b).

# The exponential distribution
A variable Y whose pdf (density) is:
$$f(y) = \frac{1}{θ}e^{-y/θ} , \space 0 < y < ∞$$
is called exponential distribution with parameter θ > 0, denoted $\epsilon$(θ)

**Gamma function:**
For $\alpha$ > 0, define $\Gamma(\alpha) = \int_0^\infty x^{\alpha-1}e^{-x}dx$  
- $\Gamma(\alpha) = (\alpha-1)\Gamma(\alpha-1)$
- $\Gamma(\alpha) = (\alpha-1)!$ if alpha is integer
- $\Gamma(\frac{1}{2}) = \sqrt\pi$ 

# The Gamma distribution
A variable X whose pdf (density) is:
$$f(x) = \frac{1}{\Gamma(\alpha)\theta^\alpha}x^{\alpha-1}e^{-x/\theta} \space, \space 0 < x < \infty$$
is called gamma distribution with parameters α and θ, denoted
G(α,θ)