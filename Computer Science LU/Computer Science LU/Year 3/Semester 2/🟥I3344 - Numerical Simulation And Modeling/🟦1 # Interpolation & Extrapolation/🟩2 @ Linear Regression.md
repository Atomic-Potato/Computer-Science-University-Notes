_Previous [[🟩1 @ Intro to Interpolation & Extrapolation]]_


---

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
**It is the discrepancy between the `true value` $y$ and the `approximate value` $\hat{y}$ by the linear equation**

## Criteria for a Best Fit / SSE

Theres a couple of approaches but this is the best one:

**Minimize the Sum of Squares of residual Errors *(SSE)* or $S_{r}$**
$$\color{magenta}\LARGE S_{r} =  \sum^{n}_{i=1} |e^2_{i}| = \sum^{n}_{i=1} (y_{i} − \hat{y})_{2} =  \sum^{n}_{i=1} (y_{i} − a_{0} − a_{1}x^i) 2$$
where n is the total number of points. ^f37339

> the SSE is **a measure of how well the regression model fits the data**. A lower SSE indicates a better fitting model, while a higher SSE indicates a poorer fitting model

Differentiating the equation with respect to each coefficient $a_{0}$ and $a_{1}$ and then minimizing $S_{r}$ would give us the equations for each coefficient:
$$\Large \color{lime} a_{1} = \frac{ n\left(  \sum x_{i}y_{i} \right) - \left( \sum x_{i} \right)\left( \sum y_{i} \right)}{n(\sum x_{i}^2) - (\sum x_{i})^2}$$
$$\Large \color{lime} a_{1}= r \cdot\left( \frac{\sigma_{y}}{\sigma_{x}} \right)$$
$$\Large \color{cyan} a_{0} = \overline{y}-a_{1} \bar{x}$$

==Note:== The linear regression model gives us with confidence the best SSE / error
## ==Reminders :== 

### Mean
$\large \overline{y}$ is the mean of y, i.e. $\Large \overline{y} = \frac{\sum y_{i}}{n}$

### Standard Deviation
allows to express the dispersion of the values around their mean i.e. the average distance between the values and their mean.

$\large σ = \sqrt{ v }$ where the variance $\Huge ν = \frac{\left[ \sum^n_{i=1}(x_{i}-\overline{x})^2 \right]}{n}$

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

# Linear Regression Error Qunatification
How to evaluate the accuracy of $a_{1}$ and $a_{0}$?
The value of [[#^f37339|SSE]] does not make it possible to evaluate the accuracy of these two coefficients.
>_For example
>an error of 2.5 on a set of data belonging to the interval [1000, 1500] is negligible in comparison with the same value on another set belonging to the interval [0,1]._

The solution would to be to **normalize the error**

## Method 1: *Normalized Root-Mean-Square Error*
Use **Normalized Root-Mean-Square Error *(NRMSE)*** 
$$MSE = \frac{SSE}{n}$$
$$RMSE=\sqrt{\frac{SSE}{n}}$$
$$\color{cyan} NRMSE = \frac{RMSE}{\overline{y}}$$
**NRMSE close to `0` ⇒ Perfect model**
**NRMSE close to `1` ⇒ Null model**

## Method 2
Compare the approximate model $\large\color{pink}\hat{y} = ax + b$ with the Null model $\large\color{pink}\hat{y} = \overline{y}$ _(where x does not intervene)_

We introduce the measure $\Large \color{cyan} R^2 = 1 − \frac{SSE}{TSS}$
Where:
- *SSE = Sum of Square Errors* $\large \color{lime} \sum^n_{i=1}(y_{i}-\hat{y})^2$
- *TSS = Total Sum of Squares* $\large \color{lime} \sum^n_{i=1}(y_{i}-\overline{y})^2$

**$R^2$ close to `0` ⇒ Perfect model**
**$R^2$ close to `1` ⇒ Null model**

![[Pasted image 20230511180525.png|500]]

==Note:== SSE < TSS since in worst case scenario the model found is the null mode