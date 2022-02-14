A **generator expression** is similar to a list comprehension, but creates an **iterable generator** object that produces values on demand. This is known as **lazy evaluation**. List comprehensions use greedy evaluation—they create lists immediately when you execute them. For large numbers of items, creating a list can take substantial memory and time. So generator expressions can reduce your program’s memory consumption and improve performance if the whole list is not needed at once.

Generator expressions have the same capabilities as list comprehensions, but you define them in parentheses instead of square brackets.

```python
numbers = [10, 3, 7, 1, 9, 4, 2, 8, 5, 6]

for value in (x ** 2 for x in numbers if x % 2 != 0):
	print(value, end='  ')

#doing this for a new list will result in an error
squares_of_odds = (x ** 2 for x in numbers if x % 2 != 0)
#<generator object <genexpr> at 0x0000021EA2D44C10>
```
