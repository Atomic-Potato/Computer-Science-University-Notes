# The uniform distribution
A random variable X whose density is:
$$\Huge f(x)=\frac{1}{b-a},\space a<x<b$$
is called uniform distribution over the interval (a,b), denoted U(a,b).

# The exponential distribution
A variable Y whose pdf (density) is:
$$\Huge f(y) = \frac{1}{θ}e^{-y/θ} , \space 0 < y < ∞$$
is called exponential distribution with parameter θ > 0, denoted $\huge \epsilon$(θ)

This function can be used in quite a lot of cases, to know when to use it, just compare the variables youre working with, with the function's graph. Usually theta is the average
![[Pasted image 20220322191357.png | 200]]

# **Gamma function:**
For $\alpha$ > 0, define $$\Huge \Gamma(\alpha) = \int_0^\infty x^{\alpha-1}e^{-x}dx$$  
- $\Huge \Gamma(\alpha) = (\alpha-1)\Gamma(\alpha-1)$
- $\Huge \Gamma(\alpha) = (\alpha-1)!$ if alpha is integer
- $\Huge \Gamma(\frac{1}{2}) = \sqrt\pi$ 

# The Gamma distribution
A variable X whose pdf (density) is:
$$\Huge f(x) = \frac{1}{\Gamma(\alpha)\theta^\alpha}x^{\alpha-1}e^{-x/\theta} \space, \space 0 < x < \infty$$
is called gamma distribution with parameters α and θ, denoted
G(α,θ)