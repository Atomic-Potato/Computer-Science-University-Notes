COMMA SEPARATED VALUES

#  Python Standard Library Module `csv`

## Writing 
```python
import csv

with open('accounts.csv', mode='w', newline='') as accounts:
	writer = csv.writer(accounts)
	writer.writerow([100, 'Jones', 24.98])
	writer.writerow([200, 'Doe', 345.67])
	writer.writerow([300, 'White', 0.00])
	writer.writerow([400, 'Stone', -42.16])
	writer.writerow([500, 'Rich', 224.62])
```
Each call to the writer’s `writerow` method receives an `iterable` to store in the file. Here we’re using lists. By default, `writerow` delimits values with commas, but you can specify custom delimiters.

## Reading
```python
with open('accounts.csv', 'r', newline='') as accounts:
	print(f'{"Account":<10}{"Name":<10}{"Balance":>10}')
	reader = csv.reader(accounts)
	for record in reader: 
		account, name, balance = record
		print(f'{account:<10}{name:<10}{balance:>10}')
```

![[Pasted image 20220203192700.png | ]]

Just as you can iterate through a file object, you can iterate through the reader object one record of `commadelimited` values at a time.

##  Reading CSV Files into Pandas `DataFrame`s
### Working with Locally Stored CSV Files
```python
import pandas as pd

df = pd.read_csv('accounts.csv', names=['account', 'name', 'balance'])
df.to_csv('accounts_from_dataframe.csv', index=False)
```
![[Pasted image 20220203193308.png]]
