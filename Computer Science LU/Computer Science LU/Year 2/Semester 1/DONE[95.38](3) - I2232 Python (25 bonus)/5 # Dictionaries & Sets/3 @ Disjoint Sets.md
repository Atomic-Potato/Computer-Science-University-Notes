# What is a disjoint-set?

A disjoint-set is a data structure that keeps track of a set of elements partitioned into a number of disjoint (non-overlapping) subsets.
In other words, disjoint set is a group of sets where no item can be in more than one set.

It is also called an union–find data structure as it supports union & find operations on subsets:
-   **Find** It determines in which subset a particular element is in and returns the representative of that particular set. An item from this set typically acts as a “representative” of the set.
-   **Union** It merges two different subsets into a single subset and representative of one set becomes representative of other.
-   The disjoint-set also supports one other important operation called **MakeSet** which creates a set containing only a given element in it.

# How does union–find work?

We can determine whether two elements are in the same subset or not by comparing the result of two **Find** operations.
If the two elements are in the same set, they have same representative else they belong to different sets.
If the union is called on two elements, we merge the two subsets which the two elements were belonging to.

# How to implement Disjoint sets?

**Disjoint-set forests** are data structures where each set is represented by a tree data in which each node holds a reference to its parent node and the representative of each set is the root of that set’s tree.
**Find** follows parent nodes until it reaches the root.
**Union** combines two trees into one by attaching the root of one tree into the root of the other

# Implementation
```python
def makeSet(universe,parent):  
    for i in universe:  
        parent[i] = i  
def Find(k,parent):  
    if parent[k] == k:  
        return k  
    return Find(parent[k],parent)  
def Union(a, b,parent):  
    x = Find(a,parent)  
    y = Find(b,parent)  
    parent[x] = y

  
universe = [1, 2, 3, 4, 5]  
parent={}  
makeSet(universe,parent)  
print(parent) #{1: 1, 2: 2, 3: 3, 4: 4, 5: 5}

Union(4, 3,parent)  # 4 and 3 are in same set  
print(parent) #{1: 1, 2: 2, 3: **3**, 4: **3**, 5: 5}  
   
Union(2, 1,parent)  # 1 and 2 are in same set  
print(parent) #{1: **1**, 2: **1**, 3: 3, 4: 3, 5: 5}  
   
Union(1, 3,parent)  # 1, 2, 3, 4 are in same set  
print(parent) #{1: **3**, 2: 1, **3**: **3**, 4: **3**, 5: 5}
```