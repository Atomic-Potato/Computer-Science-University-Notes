Lists can **dynamically resize** as necessary, growing and shrinking at execution time.

### Creating Lists (and other things)
```python
c = ['potaot', 6.9, 420]
```
You can store as many different types you want in a list

Accessing the elements of a list is just like accessing elements of an array in `c#`
`len(c) to get the length of the list. (len(c) = 3)`

Lists also can be accessed from the end by using negative indices:
![[Pasted image 20220104110422.png | 500]]
<label class="ob-comment" title="" style="">  <input type="checkbox"> <span style=""> The indices must be always of type int </span>Note</label>

`When we say something is Mutable, it means you can edit its value, elements of a list are mutable.
Only strings and tuples in a list are immutable.`

### Appending to a list with +=
```python
someList = []
for number in range (1,6)
	someList += [number]
#somelitst = [1, 2, 3, 4, 5]

letters = []
letters += 'Potato'
#letters = ['P', 'o', ... ]
```

`You can concatenate lists with +`
```python
concatList = list1 + list2
```

### Using `for` and `range` to Access List Indices and Values
```python
for i in range(len(concatenated_list)): 
	print(f'{i}: {concatenated_list[i]}')
```

### Comparison Ops
You can compare entire lists if their elements are `==` or a list is `> < >= <=`  (im not sure on what exactly the other 4 compare)
```python 
list1 == list2 (returns True or False)
```