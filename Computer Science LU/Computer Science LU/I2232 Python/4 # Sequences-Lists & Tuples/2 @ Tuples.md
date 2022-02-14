Tuples are immutable and typically store heterogeneous data, but the data can be homogeneous. A tuple’s length is its number of elements and cannot change during program execution. (but he somehow still changed it)

```python
student_tuple = ()
len(student_tuple) # 0
student_tuple = 'John', 'Green', 3.3
len(student_tuple) # 3
another_student_tuple = ('Mary', 'Red', 3.3)
a_singleton_tuple = ('red',) # note the comma # it will print ('red',)
```

### Accessing Tuple Elements
A tuple’s elements, though related, are often of multiple types. Usually, you do not iterate over them. Rather, you access each individually. Like list indices, tuple indices start at 0.

### Adding Items to a String or Tuple
As with lists, the += augmented assignment statement can be used with strings and tuples, even though they’re immutable.

```python
tuple1 = (10, 20, 30)
tuple2 = tuple1 
tuple1 += (40, 50)
# tuple2 (10, 20, 30)
# tuple1 (10, 20, 30, 40, 50)
```

**but how?**
Concatenating the tuple (40, 50) to tuple1 creates a new tuple, then assigns a reference to it to the variable tuple1—tuple2 still refers to the original tuple.
For a string or tuple, the item to the right of += must be a string or tuple, respectively— mixing types causes a `TypeError`.

### Appending Tuples to Lists
You can use += to append a tuple to a list
```
list += (6, 9)
```

### Tuples May Contain Mutable Objects
```python
student_tuple = ('Amanda', 'Blue', [98, 75, 87])
student_tuple[2][1] = 85
```
