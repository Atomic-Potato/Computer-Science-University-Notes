You can index a an element in a 2D list just like in C#
```python
a = [[77, 68, 86, 73], [96, 87, 89, 81], [70, 90, 86, 81]]

for row in a:
	for item in row:
		print(item, end=' ')
	print()
```

**How nested loops execute**
```python
for i, row in enumerate(a):
	for j, item in enumerate(row):
		print(f'a[{i}][{j}]={item} ', end=' ')
	print()
```

