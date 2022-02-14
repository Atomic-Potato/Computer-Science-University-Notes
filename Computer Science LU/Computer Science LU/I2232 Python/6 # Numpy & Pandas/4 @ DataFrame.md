A `DataFrame` is an enhanced two-dimensional array. Like Series, DataFrames can have custom row and column indices, and missing data.

# Declaration & Access
```python
import pandas

grades_dict = {'Wally': [87, 96, 70], 'Eva': [100, 87, 90],
				'Sam': [94, 77, 90], 'Katie': [100, 81, 82],
				'Bob': [83, 65, 85]}

grades = pd.DataFrame(grades_dict)
```
![[Pasted image 20220125212204.png]]
```python
#access
grades['Eva']
#Test1 100 
#Test2 87 
#Test3 90 
#Name: Eva, dtype: int64

grades.Sam
#Test1 94 
#Test2 77 
#Test3 90 
#Name: Sam, dtype: int64
```

Customizing the index
```python
grades.index = ['Test1', 'Test2', 'Test3']
```
![[Pasted image 20220125212727.png]]
### Selecting Rows via the `loc` and `iloc` Attributes
```python
grades.loc['Test1']
#Wally 87 
#Eva 100 
#Sam 94 
#Katie 100 
#Bob 83 
#Name: Test1, dtype: int64

grades.iloc[1]
#Wally 96 
#Eva 87 
#Sam 77 
#Katie 81 
#Bob 65 
#Name: Test2, dtype: int64
```
### Selecting Rows via Slices and Lists with the `loc` and `iloc` Attributes
```python
grades.loc['Test1':'Test3']
```
![[Pasted image 20220125212907.png]]
```python
grades.iloc[0:2] #same as above but only the first 2 rows
```

```python
#The following specifies which ones to show specifically 
grades.loc[['Test1', 'Test3']]
grades.iloc[[0, 2]]
```

### Selecting Subsets of the Rows and Columns
```python
grades.loc['Test1':'Test2', ['Eva', 'Katie']]
grades.iloc[[0, 2], 0:3]
```
![[Pasted image 20220125213223.png]]

### Boolean Indexing
```python
grades[grades >= 90]
grades[(grades >= 80) & (grades < 90)]
```
![[Pasted image 20220125213250.png]]


### Accessing a Specific `DataFrame` Cell by Row and Column
```python
grades.at['Test2', 'Eva'] #87
grades.iat[2, 0] #70
grades.at['Test2', 'Eva'] = 100
grades.at['Test2', 'Eva'] #100
grades.iat[1, 1] = 87
grades.iat[1, 1] #87
```

# Manipulation
Customizing a `DataFrame`’s Indices with the `index` Attribute
```python
pd.DataFrame(grades_dict, index=['Test1', 'Test2', 'Test3'])
grades.index = ['Test1', 'Test2', 'Test3']
```

### Descriptive Statistics
```python
grades.describe()
pd.set_option('precision', 2)
grades.describe()
grades.mean()
```

### Transposing the `DataFrame` with the `T` Attribute
```python
grades.T
grades.T.describe()
grades.T.mean()
```

### Sorting
```python
grades.sort_index(ascending=False)

grades.sort_index(axis=1)

grades.sort_values(by='Test1', axis=1, ascending=False)
grades.T.sort_values(by='Test1', ascending=False)
grades.loc['Test1'].sort_values(ascending=False)
```

By default the sort_index and sort_values return a copy of the original DataFrame, which could require substantial memory in a big data application. 
You can sort the DataFrame in place, rather than copying the data. To do so, pass the keyword argument inplace=True to either sort_index or sort_values.

# Useful functions
`grades.describe()`
![[Pasted image 20220125213642.png]]