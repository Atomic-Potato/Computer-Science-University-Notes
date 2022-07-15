List comprehensions can replace many for statements that iterate over existing sequences and create new lists.
```python
list1 = []

for item in range(1, 6):
	list1.append(item)
```
We can accomplish the same task in a single line of code with a list comprehension.
```python
list2 = [item for item in range(1, 6)]
```

A list comprehension’s expression can perform tasks, such as calculations, that **map** elements to new values (possibly of different types). Mapping is a common functionalstyle programming operation that produces a result with the same number of elements as the original data being mapped.
```python
list3 = [item ** 3 for item in range(1, 6)] #[1, 8, 27, 64, 125]
```

Another common functional-style programming operation is **filtering** elements to select only those that match a condition. This typically produces a list with fewer elements than the data being filtered. To do this in a list comprehension, use the **if clause**.
```python
list4 = [item for item in range(1, 11) if item % 2 == 0] #list4
```

We can also fill a list using another list with list comprehension
```python
colors = ['red', 'orange', 'yellow', 'green', 'blue']
colors2 = [item.upper() for item in colors]

# colors2 ['RED', 'ORANGE', 'YELLOW', 'GREEN', 'BLUE']
# colors  ['red', 'orange', 'yellow', 'green', 'blue']
```
