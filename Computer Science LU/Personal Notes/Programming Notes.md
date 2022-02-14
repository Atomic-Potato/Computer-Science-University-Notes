# Iterators
for your simple mind, iterators function just like a pointer
but iterators are used to go through a container of values

lets see how to use an iterator
```cpp
std::vector<int> values = {1, 2, 3, 4}

// how we usually loop over a vector
for(int i=0; i < values.size(); i++)
	std::cout << values[i] << std::endl;
	
// how we iterate over a vector using and iterator
for(int iteratorName : values)
	std::cout << iteratorName << std::endl;
// Note that this works with vectors
// because vectors contains functions for its end and beginning addresses

// what the above function basically is
for(std::vector<int>::iterator iteratorName = values.begin(); iteratorName != values.end(); iteratorName++)
	std::cout << *iteratorName << std::endl;
// we just call in the vector variable and call from it the iterator type and create a new iterator variable
// and assign it to the begining address of the vector
// The usefull thing about this one 
// is that you can modify the iterator value / address before using it for treatment
```

# std::count()
returns number of occurrences of an element in a given range. Returns the number of elements in the range [first,last) that compare equal to val.
```cpp
std::count(pointerToStart, pointerToEnd, numberSearchedFor);
```