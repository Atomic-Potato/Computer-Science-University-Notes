The built-in function `ord()` returns the numerical value of a character.
`ord('p')`

Since Python compares strings using numerical values, you must first convert each string to all lowercase or all uppercase letters. Then their numerical values will also represent alphabetical ordering.
```python
colors = ['Red', 'orange', 'Yellow', 'green', 'Blue']

min(colors, key=lambda s: s.lower()) #Blue
max(colors, key=lambda s: s.lower()) #Yellow
```

Builtin function `reversed()` returns an iterator that enables you to iterate over a sequence’s values backward.
```python
numbers = [10, 3, 7, 1, 9, 4, 2, 8, 5, 6]
reversed_numbers = [item ** 2 for item in reversed(numbers)] #[36, 25, 64, 4, 16, 81, 1, 49, 9, 100]
```

Builtin function `zip()` enables you to iterate over multiple iterables of data at the same time. The function receives as arguments any number of iterables and returns an iterator that produces tuples containing the elements at the same index in each.

```python
names = ['Bob', 'Sue', 'Amanda']
grade_point_averages = [3.5, 4.0, 3.75]

for name, gpa in zip(names, grade_point_averages):
	print(f'Name={name}; GPA={gpa}'
```
