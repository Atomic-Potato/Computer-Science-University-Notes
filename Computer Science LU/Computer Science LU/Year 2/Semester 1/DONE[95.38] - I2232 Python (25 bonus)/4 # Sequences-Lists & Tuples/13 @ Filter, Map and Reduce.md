Here we demonstrate the built-in filter and map functions for filtering and mapping, respectively. We continue discussing reductions in which you process a collection of elements into a single value, such as their count, total, product, average, minimum or maximum.

```python
numbers = [10, 3, 7, 1, 9, 4, 2, 8, 5, 6]

def is_odd(x):
	"""Returns True only if x is odd."""
	return x % 2 != 0

list(filter(is_odd, numbers)) #[3, 7, 1, 9, 5]
```
Functions that receive other functions as arguments are a functional-style capability called higherorder functions.

Function `filter` returns an iterator, so filter’s results are not produced until you iterate through them. 

This is another example of lazy evaluation.
```python
[item for item in numbers if is_odd(item)] #[3, 7, 1, 9, 5]
```

For simple functions like `is_odd` that return only a single expression’s value, you can use a lambda expression (or simply a lambda) to define the function inline where it’s needed.
```python
list(filter(lambda x: x % 2 != 0, numbers)) #[3, 7, 1, 9, 5]
```

`map()`’s first argument is a function that receives one value and returns a new value—in this case, a lambda. The second argument is an iterable of values to map. Function map uses lazy evaluation. So, we pass to the list function the iterator that map returns. This enables us to iterate through and create a list of the mapped values.

```python
list(map(lambda x: x ** 2, numbers)) #[100, 9, 49, 1, 81, 16, 4, 64, 25, 36]
```

**combining `filter` and `map`**
```python
list(map(lambda x: x ** 2, filter(lambda x: x % 2 != 0, numbers))) #[9, 49, 1, 81, 25]

#same as
[x ** 2 for x in numbers if x % 2 != 0]
```
