*Next: [[🟩2 @ Linear Regression]]*

---

In many cases, we know the values of a function _f(x)_ at a set of points $x_1 < x_2 < ... < x_N$, but we don’t have the analytic expression of the function that lets us calculate its value at an arbitrary point.

We will try to estimate f(x) for arbitrary x by drawing a curve through all the points and sometimes beyond them. _(Usually known as ”Curve Fitting”)_

# Interpolation & Extrapolation
The procedure of estimating the value of f(x) is called:
- `Interpolation` for x ∈[x1, xN]
- `Extrapolation` for x /∈ [x1,xN]

![[Pasted image 20230418194345.png]]

The form of the function that approximates the set of points should be a convenient one.
Different estimation methods are available