# i/o in c++
- the equivalent  of `#include<stdio.h>` in `c++` is `#include<cstdio>`
- we have other input/output functions in `c++` which are contained in the `#include<iostream>` library
- to print something with `<iostream>` we use
```c++
cout << "something" << "something else";
// but this will not work because we need to do
std::count << "something" << "something else";
//the '::' probably means the '.' like in C#
// you can avoid writing std:: by including the namespace like so:
using namespace std;
```
- same thing for input
```c++
cin >> variable;
```
- you can use `<< endl` for a `\n` in `cout and cin`

<label class="ob-comment" title="" style="">  <input type="checkbox"> <span style=""> Its better to use printf() and scanf() for more sophisticated `i/o`</span>Note</label>

# Arrays[] and vectors<> in c++

You can use the arrays as in c, but in c++ we will use vectors because they are much more flexible
- You declare a vector like so:
```c++
#include <vector> // you might need the namspace `std`

//... main
//you say you want the vector and its type in between <>
//the x will dictate the size of the vector and the y will intialize all the values in the vector to y
vector<int> vecName(x,y);

//Or you can do so
vector<int> vecName = {0, 1, 2, 3, ...};
```

- you can print the vector just like an array:
```c++
for(int i = 0; i < x; i++)
	printf("vecName[%d] = %d \n", i, vecName[i]);

// Or you can do
for(auto i = vecName.begin(); i < vecName.end(); i++)
	cout << *i << " ";
// the `auto` i assume automatically assigns the type for `i` i think here it will be as a pointer
// begin() and end() return a value of the location in memory 
// *i is the value of the variable the `i` is pointing to

//you can flip it to print from the end to the start with rbegin() and rend()
for(auto i = vecName.rbegin(); i != vecName.rend(); i++)
	cout << *i << " ";
```
- Accessing the elements of a vector
```c++
vecName[x]; // just like an array
vecName.at(x); // just like the above
vecName.front(); // will give the first element
vecName.back(); // will give the last element

int *pos = vecName.data(); // used when iterating, google it
```

- Some of the functions you can use with vectors
```c++
vecName.size(); // how many elements are there currently in the vector
vecName.capacity(); // how many elements this vector can fit
vecName.max_Size(); // how much vectors can fit in general if you were to extend their capacity

vecName.empty(); // self explained, returns a value of true or false
```

- How to manipulate a vector
```c++
vecName.push_back(someValue); // will add a new extra element 'some value' at the end of the array making its capacity = originalCapacity + 1

vecName.pop_back(); // will remove the last element of the array

vecName.erase(elementIndex); // self explained
vecName.insert(elementIndex, theNewValue); // slef explained

vecName.emplace_back(someValue); // will put 'someValue' in the last element of the vector

vecName.resize(someValue); // this will shrink the size of the vector to `someValue` but the capacity will stay the same (i dont think it will increase capacity if someValue > capacity)

vecName.clear(); // clears the vector
```

# Algorithms in C++
We must first `#include <algorithm>` library
- Functions in the algorithm library
```c++
//Self explained
sort(pointerToTheStartOfTheArrayOrVector, pointerToTheEndOfTheArrayOrVector);
// you can also sort a vector in reverse by doing this
sort(vect.rbegin(), vect.rend());
partial_sort(pointerToTheStartOfTheArrayOrVector, pointerToSomePlaceInTheArrayOrVector, pointerToTheEndOfTheArrayOrVector);
reverse(pointerToTheStartOfTheArrayOrVector, pointerToTheEndOfTheArrayOrVector);
```

- how to create our own custom variable. An example;
```c++
struct point2D {int x, y;}

int main(){
	// we can also create an array of these variables
	point2D pt[] = {{1,2}, {3,4}, {5,6}};
}
```
- how to use the `sort()` with an array of custom variables
```c++
//To do so we need to create a function that returns true or false as a third parameter for `sort()` that compares 2 values of our custom variable

bool comparePoints(point2D a, point2D b){
	if(a.x == b.x)
		return a.y > b.y;
	else
		return a.x > b,x;
}

int main(){
	sort(sp, sp+SizeOfArray, comparePoints);
}
```

- finding a value in an array or in a vector using `lower_bound()`:
```c++
//For the ARRAYS

//we need first the array to be sorted, same for vecs
sort(arr, arr + size);
// the lower bound function returns a pointer to the position of that value in the memory
int* pos = lower_bound(arr, arr+size, desieredValue);

//What we can do if there is no value

//if it doesnt find a value then it will just give us the garbage value in the memory
// if we get the difference bewteen the position pointer and the start of the arr pointer == to the size of the arr, it means we have reached an element which is the element that is right next to the end of array in memeory which is just a garbage value
if(pos - arr == sizeOFArr)
	//Do whatever you want
```

```C++
//For the VECTORS

sort(vect.begin(), vect.end());
// in vectors, lower_bound(); returns an iterartor
// which is declared like so
vector<int>::iterator j;
j = lower_bound(v.begin(), v.end(), desiredValue);
cout << *j;

// if the value not found
if(j == v.end())
	// do ur thing
```

# Using Pairs instead of Structs
Pairs are pretty much the same as the struct we did earlier, better shown than explained
```c++
//it is declared like so
typedef pair<anyValueType, anyValueType> theNameOfThePair;

//Example
typedef pair<bool, int> switch;
switch myPPSwitch = make_pair(true, 0);

//we can also chain pairs like so
typedef pair<int, pair<bool, bool>> chainedPair;
chainedPair ultraPP = make_pair(1, make_pair(true, false));
```

- sorting a pairs. Especially chained pairs:
```c++
vector<nameOfPair> pairs;
pairs.push_back(pair1);
pairs.push_back(pair2);
//and so on...

//Sorting works just like any normal vector
sort(pairs.begin(), pairs.end());
//the thing to notice here that it sorts them by the first pair then second
//if the second is also a pair, then after sorting the first main element of the pair, it does the same thing for this pair if possible without breaking the original sorting
```

-Printing pairs:
```c++
typedef pair<int, int> normalPairs;
printf("%d %d", normalPairs.first, normalPairs.second);

typedef pair<int, pair<int, int>> chainedPairs;
printf("%d %d", normalPairs.second.first, normalPairs.second.second);

typedef pair<str, str> strPairs;
printf("%s %s", ((string)strPairs.first).c_str(), ((string)strPairs.second).c_str());
```