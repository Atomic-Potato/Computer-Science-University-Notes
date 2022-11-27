Method `insert()` adds a new item at a specified index.
`listName.insert(index, newValue)`

You can add a new item to the end of a list with method `append()`.
`listName.append(newVal)`

Use list method `extend()` to add all the elements of another sequence to the end of a list.
`currentList.extend(newListNameOrTupleOrVal)`

Method `remove()` deletes the first element with a specified value—a `ValueError` occurs if remove’s argument is not in the list.
`listName.remove(value)`

To delete all the elements in a list, call method `clear()`.
`listName.clear()`
Or you can do this
`listName[:] = []`

List method `count()` searches for its argument and returns the number of times it is found.
`listName.count(value)`

List method `reverse()` reverses the contents of a list in place, rather than creating a reversed copy, as we did with a slice previously.
`listName.reverse()`

List method `copy()` returns a new list containing a shallow copy of the original list.
`copiedList = listName.copy()`
