You can import the module and create an array like so
```python
import numpy as np

numbers = np.array([2, 3, 5, 7, 11]) #array([ 2, 3, 5, 7, 11])
type(numbers) #numpy.ndarray

#2d Array
np.array([[1, 2, 3], [4, 5, 6]]) #array([[1, 2, 3], [4, 5, 6]])
```

# **`array` Attributes:**
You can check the element type with an array’s `dtype` attribute.
```python
integers = np.array([[1, 2, 3], [4, 5, 6]])
floats = np.array([0.0, 0.1, 0.2, 0.3, 0.4])

integers.dtype #dtype('int32')
floats.dtype #dtype('float64')
```

The attribute `ndim` contains an array’s number of dimensions and the attribute `shape` contains a tuple specifying an array’s dimensions.
```python
integers.ndim #2
floats.ndim #1
integers.shape #(2, 3)
floats.shape #(5,)
```

You can view an array’s total number of elements with the attribute `size` and the number of bytes required to store each element with `itemsize`.
```python
integers.size #6
integers.itemsize #4
```

How to iterate through a multidimensional array
```python
for row in integers:
	for column in row:
		print(column, end='  ')
	print()
# Or
for i in integers.flat:
	print(i, end='  ')

# same result
```

# Filling arrays
### With a specific value
NumPy provides functions `zeros`, `ones` and `full` for creating arrays containing 0s, 1s or a specified value, respectively. By default, zeros and ones create arrays containing float64 values.
The first argument to these functions must be an integer or a tuple of integers specifying the desired dimensions. For an integer, each function returns a one-dimensional array with the specified number of elements.
```python
import numpy as np

np.zeros(5) #array([0., 0., 0., 0., 0.])
np.ones((2, 4), dtype=int) #array([[1, 1, 1, 1], [1, 1, 1, 1]])
np.full((3, 5), 13) #array([[13, 13, 13, 13, 13], [13, 13, 13, 13, 13], [13, 13, 13, 13, 13]])
```

### With ranges
NumPy’s `arange` function creates integer ranges—similar to using builtin function range. In each case, arange first determines the resulting array’s number of elements, allocates the memory, then stores the specified range of values in the array.
```python
np.arange(5) #array([0, 1, 2, 3, 4])
np.arange(5, 10) #array([5, 6, 7, 8, 9])
np.arange(10, 1, -2) #array([10, 8, 6, 4, 2])
```

### With `linespace`
You can produce evenly spaced floating-point ranges with NumPy’s `linspace` function. The function’s first two arguments specify the starting and ending values in the range, and the ending value is included in the array. The optional keyword argument num specifies the number of evenly spaced values to produce—this argument’s default value is 50.
```python
np.linspace(0.0, 1.0, num=5)
#array([0. , 0.25, 0.5 , 0.75, 1. ])
```

# Manipulating arrays
You also can create an array from a range of elements, then use array method `reshape` to transform the one-dimensional array into a multi-dimensional array.
```python
np.arange(1, 21).reshape(4, 5)
#array([[ 1, 2, 3, 4, 5], 
		#[ 6, 7, 8, 9, 10], 
		#[11, 12, 13, 14, 15], 
		#[16, 17, 18, 19, 20]])
```

When displaying an array, if there are 1000 items or more, NumPy drops the middle rows, columns or both from the output.
![[Pasted image 20220122121954.png | 500]]

## `array` Operators
```python
numbers = np.arange(1, 6) #array([1, 2, 3, 4, 5])
numbers * 2 #array([ 2, 4, 6, 8, 10])
numbers ** 3 #array([ 1, 8, 27, 64, 125], dtype=int32)
# numbers is unchanged by the arithmetic operators
# however the next operation will change the original array
numbers += 10 #array([11, 12, 13, 14, 15])

# The following operations require both arrays to be of the same size and shape
numbers2 = np.linspace(1.1, 5.5, 5) #array([1.1, 2.2, 3.3, 4.4, 5.5])
numbers * numbers2 #array([12.1, 26.4, 42.9, 61.6, 82.5]) # this also gives a copy
```

#### Comparison operators
```python
numbers >= 13 #array([False, False, True, True, True])
numbers2 < numbers #array([ True, True, True, True, True])
numbers == numbers2 #array([False, False, False, False, False])
```

#### Calculation functions
`array.sum()` sums and returns all the elements in the array
`array.min()` gets the minimum element in the array
`array.max()` gets the max element in the array
`array.mean()` i dont need to explain now
`array.std()` i think this one is the standard deviation
`array.var()` variance
*Works on multidimensional arrays as well*

You can apply it to only rows / columns with the `axis` argument, it will return an array containing the results for each column / row
![[Pasted image 20220122123947.png | 500]]

#### Universal functions
`numpy.sqrt(array)` returns an array of sqrt of each element
`numpy.add(arr1, arr2)` adds the elements and returns an array 
`numpy.add(arr1, x)` same as above but you can use a value instead
*you can multiply a 2D array with a 1D array as long as they have the same row size*

## Indexing and Slicing
You can access an element in a multidimensional array like so
```python
array[0, 1] # row 0, column 1
```

Getting a `subset of rows`
![[Pasted image 20220122125114.png]]

Getting a `subset of columns`
![[Pasted image 20220122125243.png]]

## `reshape()` VS `resize()`
The array methods reshape and resize both enable you to change an array’s dimensions. Method reshape returns a view (shallow copy) of the original array with the new dimensions. It does not modify the original array.
```python
#array([[ 87, 96, 70], [100, 87, 90]])
array.reshape(1, 6) #array([[ 87, 96, 70, 100, 87, 90]])
```
`resize()` functions the same way but it modifies the original array.

## `faltten()` VS `ravel()`
both `flatten` and `ravel` create flatten a multidimensional array into a single row. Tho `flatten` creates a deep copy while `ravel` creates a view of the array, thus editing a raveled array modifies the original array it got raveled from.
```python
array.flatten()
array.ravel()
```
![[Pasted image 20220122144120.png | 300]]

## Other smol things
- **Transpose:**
You get the transpose of an array, so that the rows become the columns and vice versa, by using the attribute `T`
`array.T`
It returns a shallow copy of the array.

- **Horizontal and vertical stacking**
![[Pasted image 20220122144622.png | 400]]

# Views: Shallow Copies
When copying an array into another, everything applied to one of the arrays gets applied to the other array (idk how this is useful)

Declaration:
```python
numbers = numpy.arange(1, 6)
numbers2 = numbers.view()
```

You can also slice views
```python
numbers2 = numbers[0:3]
# this means you cant apply any changes to the first array if the index is out of bounds in the second array
```

You can just copy an array into another using `.copy()` without affecting both arrays when one is edited
`arr2 = arr1.copy()`

If you need deep copies of other types of Python objects, pass them to the `copy` module’s `deepcopy` function.
