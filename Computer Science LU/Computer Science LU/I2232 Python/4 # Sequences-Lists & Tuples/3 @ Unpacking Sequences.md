You can unpack any sequence’s elements by assigning the sequence to a comma-separated list of variables. A `ValueError` occurs if the number of variables to the left of the assignment symbol is not identical to the number of elements in the sequence on the right.

```python
student_tuple = ('Amanda', [98, 85, 87])
first_name, grades = student_tuple
# first_name: Amanda
# grades: [98, 85, 87]

first, second = 'hi'
print(f'{first} {second}') #h i

number1, number2, number3 = [2, 3, 5]
print(f'{number1} {number2} {number3}') #2 3 5

number1, number2, number3 = range(10, 40, 10)
print(f'{number1} {number2} {number3}') #10 20 30
```

### Swapping Values Via Packing and Unpacking
You can swap two variables’ values using sequence packing and unpacking.

```python
number1 = 99
number2 = 22
number1, number2 = (number2, number1)
print(f'number1 = {number1}; number2 = {number2}') #number1 = 22; number2 = 99
```

### Accessing Indices and Values Safely with Built-in Function enumerate
Earlier, we called `range` to produce a sequence of index values, then accessed list elements in a for loop using the index values and the subscription operator (`[]`). This is error-prone because you could pass the wrong arguments to `range`. If any value produced by `range` is an out-of-bounds index, using it as an index causes an `IndexError`.

The preferred mechanism for accessing an element’s index and value is the builtin function `enumerate`. This function receives an iterable and creates an iterator that, for each element, returns a tuple containing the element’s index and value. The following  code uses the builtin function list to create a list containing enumerate’s results:

```python
colors = ['red', 'orange', 'yellow']

list(enumerate(colors)) #[(0, 'red'), (1, 'orange'), (2, 'yellow')]
tuple(enumerate(colors)) #((0, 'red'), (1, 'orange'), (2, 'yellow'))

for index, value in enumerate(colors):
	print(f'{index}: {value}')
#0: red 
#1: orange 
#2: yellow
```

### Creating a Primitive Bar Chart
The following script creates a primitive bar chart where each bar’s length is made of asterisks `(*)` and is proportional to the list’s corresponding element value. We use the function `enumerate` to access the list’s indices and values safely.

```python
"""Displaying a bar chart"""
numbers = [19, 3, 15, 7, 11]

print('\nCreating a bar chart from numbers:')
print(f'Index{"Value":>8} Bar')
for index, value in enumerate(numbers):
	print(f'{index:>5}{value:>8} {"*" * value}')
```
Output:
![[Pasted image 20220104114727.png | 300]]