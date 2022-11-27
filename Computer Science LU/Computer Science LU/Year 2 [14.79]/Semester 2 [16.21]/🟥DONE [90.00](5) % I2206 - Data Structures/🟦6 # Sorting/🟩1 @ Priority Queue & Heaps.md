A heap is a tree with the following conditions:
- The value of the node should $\large \leq \space or \space \geq$  than of its children
- All leaves should have a height of `h` or `h-1` from a previous node
- Should form a complete binary tree
![[Pasted image 20220716230425.png | 500]]

There are two types of **heaps:**
- `Min heap:` where the root is the minimum
- `Max heap:` where the root is the maximum

# Static implementation
*(We'll use max heaps in this implementation)*
![[Pasted image 20220716230645.png | 500]]

- `Decleration:`
	```c
	typedef struct
	{
		int* array;
		int count;     //current number of nodes 
		int capacity;  //maximum count
		int heap_type; //min or max heap 
	}*Heap;
	```
- `Creation & Utilities:`
	```c
	Heap CreateHeap(int capacity, int heap_type)
	{
		Heap h = (Heap)malloc(sizeof(Heap));

		if(!h)
			return NULL;
		
		h->heap_type = heap_type;
		h->capacity = capacity;
		h->array = (int*)malloc(sizeof(int));
		
		if(!h->array)
			return NULL;
			
		return h;
	}
	//TIME COMPLEXITY: O(1)

	//For a node at location i in the array,
	//its parent is loacted at position (i-1)/2
	int Parent(Heap h, int i)
	{
		if(i<=0 || i>h->count)
			return -1;
		return (i-1)/2;
	}
	//TIME COMPLEXITY: O(1)

	//For a node at location i in the array,
	//itsh childrent are located at positions:
	//2*i+1 right
	//2*i+2 left
	int LeftChild(Heap h, int i)
	{
		int left = 2*i+1;
		if(left >= h->count)
			return -1;
		return left;
	}

	int RightChild(Heap h, int i)
	{
		int right = 2*i+2;
		if(right >= h->count)
			return -1;
		return right;
	}
	//TIME COMPLEXITY: O(1)

	//Max element is the root
	int GetMaximum(Heap h)
	{
		if(h->count == 0)
			return -1;
		return h->arry
	}
	//TIME COMPLEXITY: O(1)
	```

## Heapifying an element
When adding new elements to the array  we need to make sure that they are in the right spot, because they can be greater than their parents

**To heapify a node, we swap it with the max of its children, and keep repeating this process until we cant swap anymore. Repeat the whole operation on a new node of the tree until all of the tree nodes are heapified**

```c
void PercolateDown(Head *h, int i) //Heapifying the element i
{
	int left = LeftChild(*h, i);
	int right = RightChild(*h, i);
	int max;

	if(left != -1 && (*h)->array[left] > (*h)->array[i])
		max = left;
	else if(right != -1 && && (*h)->array[right] > (*h)->array[i])
		max = right;
	else
		max = i;

	if(max != i)//Swap
	{
		int aux = (*h)->array[i];
		(*h)->array[i] = (*h)->array[max];
		(*h)->array[max] = (*h)->array[i];
		
		PercolateDown(h, max); //move on with the node
	}
}
//TIME COMPLEXITY: O(log(n))
```

## Deleting root 
- save the first element 
- save the last element into the first element location
- **PercolateDown()** the first element
```c
int DeleteMax(Heap* h)
{	
	if((*h)->count == 0)
		return -1;
		
	int data = (*h)->array[0];
	(*h)->array[0] = (*h)->array[(*h)->count-1];
	(*h)->count--;
	
	PercolateDown(h, 0);
	
	return data;
}
//TIME COMPLEXITY: O(log(n))
```

## Inserting an element
- increase heap size
- put new element at the end of the array
- Heapify from **bottom to top**
```c
int Insert(Heap *h, int data)
{
	if((*h)->count == (*h)->capcity)
		return -1;
		
	(*h)->count++;
	
	int i;
	for(i = (*h)->count-1; i > 0 && data > Parent(h, i); i=(i-1)/2)
		(*h)->array[i] = (*h)->array[(i-1)/2];
	
	(*h)->array[i] = data;
	return i;
}
```

## Destroying Heap
```c
void DestroyHeap(Heap* h)
{
	if(h==NULL)
		return;
	
	free((*h)->array);
	free(h);
	
	h = NULL;
}
```

## Building Heap
```c
void BuildHeap(Heap* h, int A[], int n)
{
	if(h==NULL || n > (*h)->capacity)
		return;
		
	for(int i=0; i < n; i++)
		(*h)->array[i] = A[i];
	
	(*h)->count = n;
	
	for(int i=(n-1)/2; i>=0; i--)
		PercolateDown(h, i);
}
//Complexity = O(n)
```