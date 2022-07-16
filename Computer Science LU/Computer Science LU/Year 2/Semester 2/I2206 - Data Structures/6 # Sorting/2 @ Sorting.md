# Bubble Sort
```c
//keep swaping pairs until a loop where you dont swap
void BubbleSort(int A[], int n)
{
	int swapped = 1;
	
	for(int i = n-1; i >= 0 && swapped; i--)
	{
		swapped = 0;
		
		for(int j=0; j<pass; j++)
		{
			if(A[i] > A[i+1])
			{
				//Swap them
				swapped = 1;
			}
		}
	}
}
//Complexity = O(n^2)
```

# Selection Sort
move up the array, find the minimum and swap it with the current
```c
void SelectionSort(int A[], int n)
{
	for(int i=0; i < n-1; i++)
	{
		int min = i;
		for(int j=i+1; j < n; j++)
			//Compare and replace with min
		
		//Swap at i with at min
	}
}
//Complexity = O(n^2)
```

# Insertion Sort
![[Pasted image 20220717000010.png | 450]]
![[Pasted image 20220717000346.png | 450]]
```c
void InsertionSort(int A[], int n)
{
	for(int i=1; i<n; i++)
	{
		int v = A[i];
		
		for(int j=i; A[j-1] > v && j > 0; j--)
			A[j] = A[j-1];
			
		A[j] = v;
	}
}
```

# Quick Sort
![[Pasted image 20220717000315.png | 450]]
![[Pasted image 20220717000431.png | 450]]
```c
QuickSort(A, 0, N-1);

void QuickSort(int A[], int low, int high)
{
	int pivot;
	
	if(high > low)
	{
		pivot = Partition(A, low, high);
		QuickSort(A, low, pivot-1);
		QuickSort(A, pivot+1, high);
	}
}

int Partition(int A[], int low, int high)
{
	int left = low+1;
	int right = high;
	int pivot_item = A[low];
	
	while(left <= right)
	{
		//Move left while item < pivot
		while(A[left] <= pivot_item && left <= right)
			left++;
		//Move right while item > pivot
		while(A[right] ? pivot_item && left <= right)
			right--;
		
		if(left < right)
		{
			swap(A, left, right);
			left++;
			right--;
		}
	}

	//Right is the final position for the pivot
	A[low] = A[right];
	A[right] = pivot_item;
	return right;
}
//Complexity (pivot in middle): O(n^2)
//Complexity (pivot on edges): O(n*log(n))
```
![[Pasted image 20220717000801.png | 400]]

# Merge Sort
![[Pasted image 20220717001343.png | 450]]
![[Pasted image 20220717001357.png | 450]]
```c
void Fusion(int T, int lower, int upper, int middle)
{
	int c[upper-lower+1];
	int i = lower;
	int j = middle+1;
	int k = 0;
	
	while(i<=middle && j <= upper;)
		if(T[i] < T[j])
			c[k++] = T[i++];
		else
			c[k++] = T[j++];
	
	//Copy remaing elements into c
	while(i<=middle)
		c[k++] = T[i++];
	while(j<=upper)
		c[k++] = T[j++];
	//Copy elements back to T
	for(i=lower, j=0; j<k; i++, j++)
		T[i] = c[j];
}

void MergeSort(int T[], int lower, int upper)
{
	if(lower < upper)
	{
		int middle = (lower+upper)/2;
		
		MergeSort(T, lower, middle);
		MergeSort(T, middle+1, upper);
		
		Fusion(T, lower, upper, middle);	
	}
}
//Complexity: Nlog(N)
```

# HeapSort
![[Pasted image 20220717002309.png | 450]]
```c
void HeapSort(int A[], int n)
{
	Heap h = CreateHeap(n, 1);
	BuildHeap(&h, A, n);
	
	int old_size = h->count;
	
	for(int i=n-1; i>=0; i--)
	{
		//root is the largest element
		int temp = h->array[0];
		h->array[0] = h->array[h->count-1];
		h->array[h->count-1] = temp;
		h->count--;
		PercolateDown(&h, 0);
	}
	
	for(int i=0; i<old_size; i++)
		A[i] = h->array[i];
}
//Complexity = O(n*log(n))
```