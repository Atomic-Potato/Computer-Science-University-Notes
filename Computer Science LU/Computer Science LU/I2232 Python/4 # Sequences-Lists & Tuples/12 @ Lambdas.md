The `lambda` keyword in Python provides a shortcut for declaring small anonymous functions. Lambda functions behave just like regular functions declared with the def keyword. They can be used whenever function objects are required

Example:
```python
add = lambda x, y: x + y
add(5, 3) # retunrs 8

#or you can do this
(lambda x, y: x + y)(5, 3) # returns 8
```

There’s another syntactic difference between lambdas and regular function definitions. Lambda functions are restricted to a single expression. This means a lambda function can’t use statements or annotations—not even a `return` statement.

Technically, any time you’re expected to supply a function object you can use a lambda expression. And because lambdas can be anonymous, you don’t even need to assign them to a name first.

The most frequent use case for lambdas is writing short and concise key funcs for sorting iterables by an alternate key:
```python
tuples = [(1, 'd'), (2, 'b'), (4, 'a'), (3, 'c')]
sorted(tuples, key=lambda x: x[1]) #[(4, 'a'), (2, 'b'), (3, 'c'), (1, 'd')]
#In the above example, we’re sorting a list of tuples by the second value
#in each tuple. In this case, the lambda function provides a quick way
#to modify the sort order.
```

Here’s another interesting thing about lambdas: Just like regular nested functions, lambdas also work as *lexical closures*. It’s just a fancy name for a function that remembers the values from the enclosing lexical scope even when the program flow is no longer in that scope. Here’s a (fairly academic) example to illustrate the idea:

```python
def make_adder(n):
	return lambda x: x + n
plus_3 = make_adder(3)
plus_5 = make_adder(5)

plus_3(4) #7
plus_5(4) #9
```

In the above example, the x + n lambda can still access the value of n even though it was defined in the make_adder function (the enclosing scope).

Usually it’s much cleaner to go with a list comprehension or generator expression.
```python
# Harmful:
list(filter(lambda x: x % 2 == 0, range(16)))

# Better:
[x for x in range(16) if x % 2 == 0]

#[0, 2, 4, 6, 8, 10, 12, 14]
```

