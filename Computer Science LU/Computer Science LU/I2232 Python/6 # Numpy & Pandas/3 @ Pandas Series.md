%%xxx.... ?%%
==I lost my internet on this one, i couldnt download the library==
Pandas library provides two key collections—`Series` for one-dimensional collections and `DataFrames` for two-dimensional collections. You can use pandas’ `MultiIndex` to manipulate multi-dimensional data in the context of Series and DataFrames.

# Declaration & Access
By default, a Series has integer indices numbered sequentially from 0.
```python
import pandas
grades = pandas.Series([87, 100, 94])

#the following fills the series with the same value
pandas.Series(98.6, range(3))

#you can access elements just like a normal array
grades[i]
```

## Custom indices
You can specify custom indices with the `index` keyword argument.
```python
grades = pandas.Series([87, 100, 94], index=['Wally', 'Eva', 'Sam'])
```

### Dictionary initializers
If you initialize a Series with a dictionary, its keys become the Series’ indices, and its values become the Series’ element values.
```python
grades = pandas.Series({'Wally': 87, 'Eva': 100, 'Sam': 94})
```

If the custom indices are strings that could represent valid Python identifiers, pandas automatically adds them to the Series as attributes that you can access via a dot (.).
`grades.Wally` //87
`grades.dtype` //dtype('int64')
`grades.values` //array([ 87, 100, 94], dtype=int64)

## Creating a series of strings
If a Series contains strings, you can use its `str` attribute to call string methods on the elements.
```python
hardware = pd.Series(['Hammer', 'Saw', 'Wrench'])
#0 Hammer 
#1 Saw 
#2 Wrench 
#dtype: object

hardware.str.contains('a')
#0 True 
#1 True 
#2 False 
#dtype: bool

hardware.str.upper()
```

# Displaying
Pandas displays a Series in twocolumn format with the indices left aligned in the left column and the values right aligned in the right column. 
After listing the Series elements, pandas shows the data type (dtype) of the underlying array’s elements.

# Manipulation
### Useful functions
`series.count()`
`series.mean()`
`series.min()`
`series.max()`
`series.std()`

`series.describe()` 
![[Pasted image 20220125211638.png]]


