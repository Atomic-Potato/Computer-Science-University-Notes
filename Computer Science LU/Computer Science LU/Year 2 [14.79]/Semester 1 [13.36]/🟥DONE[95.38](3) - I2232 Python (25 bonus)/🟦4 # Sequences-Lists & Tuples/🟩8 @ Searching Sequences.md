# List Method index
List method index takes as an argument a search key—the value to locate in the list— then searches through the list from index 0 and returns the index of the first element that matches the search key.
`listName.index(valueSearchedFor)`

You can also add another argument to the function which is the starting index of the search
`listName.index(value, startIndex)`
And you can also specify the ending index
`listName.index(value, startIndex, endingIndex)`

# Using `*=` on lists
`*=` to multiply a sequence—that is, append a sequence to itself multiple times.
```python
# current list [3, 7, 1, 4, 2, 8, 5, 6]
numbers *= 2; # [3, 7, 1, 4, 2, 8, 5, 6, 3, 7, 1, 4, 2, 8, 5, 6]
```

# Operators `in` and `not in`
```python
69 in listName #returns true if 69 is in the list or false if not
420 not in listName #returns true if 420 is not in the list or false if its in the list
```

You can use the operator `in` to ensure that calls to method index do not result in `ValueErrors` for search keys that are not in the corresponding sequence. 
```python
if value in listName:
	#execute
```

# Built-In Functions `any` and `all`
Sometimes you simply need to know whether any item in an iterable is `True` or whether all the items are `True`. The built-in function `any` returns `True` if any item in its iterable argument is `True`. The built-in function `all` returns `True` if all items in its iterable argument are `True`. Recall that nonzero values are `True` and 0 is `False`. Non-empty iterable objects also evaluate to `True`, whereas any empty iterable evaluates to `False`. Functions any and all are additional examples of internal iteration in functional-style programming.