The del statement also can be used to remove elements from a list and to delete variables from the interactive session. You can remove the element at any valid index or the element(s) from any valid slice.

### Deleting the Element at a Specific List Index
```python
numbers = list(range(0, 10)) #[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

del numbers[-1] #[0, 1, 2, 3, 4, 5, 6, 7, 8]
del numbers[0:2] #[2, 3, 4, 5, 6, 7, 8]
del numbers[::2] #[3, 5, 7]
del numbers[:] #[]
```
