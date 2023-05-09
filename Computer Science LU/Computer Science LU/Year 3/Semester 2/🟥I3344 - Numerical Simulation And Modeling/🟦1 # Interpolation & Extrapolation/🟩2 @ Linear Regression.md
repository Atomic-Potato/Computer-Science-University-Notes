Polynomial approximation is usually used to find a polynomial function of order n *(for n points)* 
$$\large f (x) = a_{n−1}x^{n−1} + ... + a_{0}$$
Finding coefficients $a_{i}$ requires resolving a system of n equations in n unknowns

Different methods were proposed for polynomial approximations. The resulting curve will pass through all the n points.

![[Pasted image 20230509184308.png|400]]

When data exhibit a significant degree of error or *“noise”*, the strategy is to derive a single curve that represents the general trend of these data.
Because any individual data point may be incorrect, no effort is made to intersect every point. 
The curve is designed to follow the pattern of the points taken as a group.

One approach of this nature is called [[#Least-Squares Regression]]

# Least-Squares Regression
![[Pasted image 20230509184434.png|500]]

Simplest example of a least-squares approximation is fitting a straight line to a set of paired observations.
The mathematical expression for the straight line is:
$$\large y = a_{0} + a_{1}x + e$$
Where:
- `a0` and `a1` are coefficients representing the `intercept` and the `slope` respectively
- `e is the error`, or residual, between the model and the observations

The `error (e)` can be represented by rearranging the equation as:
$$\Large \color{cyan} e = y − (a_{0} + a_{1}x) = y − \hat{y}$$
**It is the discrepancy between the true value of $y$ and the approximate value $\hat{y}$ by the linear equation**

## Criteria for a Best Fit
Theres a couple of approaches but this is the best one:

**Minimize the Sum of Squares of residual Errors *(SSE)* or $S_{r}$**
$$\large S_{r} = \sum^{n}_{i=1} |e^2_{i}| = \sum^{n}_{i=1} (y_{i} − \hat{y})_{2} = \sum^{n}_{i=1} (y_{i} − a_{0} − a_{1}x^i) 2$$
where n is the total number of points.

Differentiating the equation with respect to each coefficient $a_{0}$ and $a_{1}$ and then minimizing $S_{r}$ would give us the equations for each coefficient:
$$\Large \color{lime} a_{1} = \frac{ n\left(  \sum x_{i}y_{i} \right) - \left( \sum x_{i} \right)\left( \sum y_{i} \right)}{n(\sum x_{i}^2) - (\sum x_{i})^2}$$
$$\Large \color{lime} a_{1}= r \cdot\left( \frac{\sigma_{y}}{\sigma_{x}} \right)$$
$$\Large \color{cyan} a_{0} = \overline{y}-a_{1} \bar{x}$$
## ==Reminders :== 

### Mean
$\large \overline{y}$ is the mean of y, i.e. $\large \overline{y} = \frac{\sum y_{i}}{n}$

### Standard Deviation
allows to express the dispersion of the values around their mean i.e. the average distance between the values and their mean.

$\large σ = \sqrt{ v }$ where the variance $\huge ν = \frac{\left[ \sum^n_{i=1}(x_{i}-\overline{x})^2 \right]}{n}$

### [[🟩3 @ Mathematical expectation#Coefficient of correlation|Correlation]]
Describe the relation between two variables
$$\Large r = cor(x,y) = \frac{cov(x,y)}{σ_{x}\cdotσ_{y}}$$
$$\Large  cov(x,y)=\frac{\sum^n_{i=1}(x_{i}-\bar{x})(y_{i}-\bar{y})}{n}$$
The correlation coefficient r ∈ [-1, 1] in contrast to the covariance that is influenced by the range of values of x and y.

Three types of correlation: 
- **Positive correlation:** x $\nearrow$ ⇒ y $\nearrow$ 
- **Negative correlation:** x $\nearrow$ ⇒ y $\searrow$ 
- **Zero correlation:** No relationship exists between x and y. 

The closer the value is to 1 or -1, the stronger the link.

# Quantification of Error of Linear Regression