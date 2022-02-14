A set is an unordered collection of unique values. Sets may contain only immutable objects, like strings, ints, floats and tuples that contain only immutable elements.
Though sets are iterable, they are not sequences and do not support indexing and slicing with square brackets, `[]`. Dictionaries also do not support slicing.

# Declaration 
```python
colors = {'red', 'orange', 'yellow', 'green', 'red', 'blue'}
#{'blue', 'green', 'orange', 'red', 'yellow'}
```
Notice that the duplicate string 'red' was ignored (without causing an error). An important use of sets is **duplicate elimination**, which is automatic when creating a set. 
Also, the resulting set’s values are not displayed in the same order. Though the color names are displayed in sorted order, sets are unordered. You should not write code that depends on the order of their elements.

`len(set)` is possible as well

Creating a Set with the Built-In `set` Function
```python
numbers = list(range(10)) + list(range(5)) #numbers = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4]
set(numbers) #{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
```

Sets are mutable—you can add and remove elements, but set elements must be immutable. Therefore, a set cannot have other sets as elements. 
A `frozenset` is an immutable set—it cannot be modified after you create it, so a set can contain frozensets as elements. The builtin function `frozenset` creates a frozenset from any iterable.

# Accessing
`in` and `not in` are also possible in sets
```python
for color in colors:
	print(color.upper(), end=' ') #ORANGE BLUE RED GREEN YELLOW
```

# Comparing Sets
`!= & ==` function like in dics

The `<` operator tests whether the set to its left is a proper subset of the one to its right —that is, all the elements in the left operand are in the right operand, and the sets are not equal.
```python
{1, 3, 5} < {3, 5, 1} == False
{1, 3, 5} < {7, 3, 5, 1} == True
```
The `<=` operator tests whether the set to its left is an **improper subset** of the one to its right—that is, all the elements in the left operand are in the right operand, and the sets  might be equal.
```python 
{1, 3, 5} <= {3, 5, 1} == True
{1, 3} <= {3, 5, 1} == True 
```

You may also check for an **improper subset** with the set method `issubset`.
```python
{1, 3, 5}.issubset({3, 5, 1}) == True
{1, 2}.issubset({3, 5, 1}) == False
```

The `>` operator tests whether the set to its left is a **proper superset** of the one to its right—that is, all the elements in the right operand are in the left operand, and the left operand has more elements.
The `>=` operator tests whether the set to its left is an **improper superset** of the one to its right—that is, all the elements in the right operand are in the left operand, and the sets might be equal.
You may also check for an **improper superset** with the set method `issuperset`.

#  Mathematical Set Operations
The **union** of two sets is a set consisting of all the unique elements from both sets. You can calculate the union with the `|` operator or with the set type’s `union` method.
```python
{1, 3, 5} | {2, 3, 4} #{1, 2, 3, 4, 5}
{1, 3, 5}.union([20, 20, 3, 40, 40]) #{1, 3, 5, 20, 40}
```

The **intersection** of two sets is a set consisting of all the unique elements that the two sets have in common. You can calculate the intersection with the `&` operator or with the set type’s `intersection` method. (Functions just like above)

The **difference** between two sets is a set consisting of the elements in the left operand that are not in the right operand. You can calculate the difference with the `-` operator or with the set type’s `difference` method. (Functions same as above)

The **symmetric difference** between two sets is a set consisting of the elements of both sets that are not in common with one another. You can calculate the symmetric difference with the `^` operator or with the set type’s `symmetric_difference` method. (Functions same as above)
```python
{1, 3, 5} ^ {2, 3, 4} #{1, 2, 4, 5}
```

Two sets are **disjoint** if they do not have any common elements. You can determine this with the set type’s `isdisjoint` method. (Functions same as above) (Returns `True` or `False`)

# Mutable Set Operators and Methods
The operators and methods presented in the preceding section each result in a new set.
Here we discuss operators and methods that modify an existing set.

Like operator `|`,  union augmented assignment `|=` performs a set union operation, but `|=` modifies its `left` operand.

The set type’s `update` method performs a union operation modifying the set on which it’s called—the argument can be any iterable.
```python
numbers = {1, 2, 3, 4, 5}
numbers.update(range(10)) #{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
```

Set method `add` inserts its argument if the argument is not already in the set; otherwise, the set remains unchanged.
```python
numbers.add(17)
numbers.add(3)
#{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 17}
```

Set method `remove` removes its argument from the set—a `KeyError` occurs if the value is not in the set.
```python
numbers.remove(3) #{0, 1, 2, 4, 5, 6, 7, 8, 9, 17}
```
Method `discard` also removes its argument from the set but does not cause an exception if the value is not in the set.

You also can remove an arbitrary set element and return it with `pop`, but sets are unordered, so you do not know which element will be returned.
```python
numbers.pop() #idk from what i saw it always removed the first element
```

Finally, method `clear` empties the set on which it’s called.
`set.clear()`

# Set Comprehensions
Like dictionary comprehensions, you define set comprehensions in curly braces.
```python
numbers = [1, 2, 2, 3, 4, 5, 6, 6, 7, 8, 9, 10, 10]
evens = {item for item in numbers if item % 2 == 0} #{2, 4, 6, 8, 10}
```