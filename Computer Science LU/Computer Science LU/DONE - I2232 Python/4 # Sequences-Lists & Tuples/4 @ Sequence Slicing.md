# **Slicing**: list_name[start:stop[:step]]

You can slice sequences to create new sequences of the same type containing subsets of the original elements. Slice operations can modify mutable sequences—those that do not modify a sequence work identically for lists, tuples and strings.

### Specifying a Slice with Starting and Ending Indices
```python
numbers = [2, 3, 5, 7, 11, 13, 17, 19]
numbers[2:6] # [5, 7, 11, 13]
```
The original list is not modified.

### Specifying a Slice with Only an Ending Index
```python
numbers[:6]  #[2, 3, 5, 7, 11, 13]
numbers[0:6] #[2, 3, 5, 7, 11, 13]
```
### Specifying a Slice with Only a Starting Index
```python
numbers[6:]             #[17, 19]
numbers[6:len(numbers)] #[17, 19]
```
### Specifying a Slice with No Indices
```python
numbers[:] #[2, 3, 5, 7, 11, 13, 17, 19]
```
**`Important note:`**
Though slices create new objects, slices make shallow copies of the elements—that is, they copy the elements’ references but not the objects they point to. So, in the snippet above, the new list’s elements refer to the same objects as the original list’s elements, rather than to separate copies.
### Slicing with Steps
```python
numbers[::2] #[2, 5, 11, 17]
```

### Slicing with Negative Indices and Steps
```python
numbers[::-1] #[19, 17, 13, 11, 7, 5, 3, 2]
numbers[-1:-9:-1] #[19, 17, 13, 11, 7, 5, 3, 2]
```

### Modifying Lists Via Slices
You can modify a list by assigning to a slice of it—the rest of the list is unchanged.
```python
numbers[0:3] = ['two', 'three', 'five'] #['two', 'three', 'five', 7, 11, 13, 17, 19]
numbers[0:3] = [] #[7, 11, 13, 17, 19]

numbers[::2] = [100, 100, 100, 100] #[100, 3, 100, 7, 100, 13, 100, 19]
```