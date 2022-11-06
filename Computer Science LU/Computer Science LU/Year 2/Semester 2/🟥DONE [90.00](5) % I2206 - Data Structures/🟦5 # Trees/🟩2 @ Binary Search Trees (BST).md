In this kind of tree all the the `left subtree` elements data should be **less** than the `root` data and the `right subtree` elements data should be **greater** than the root data.
![[Pasted image 20220628145027.png | 550]]

This can help us reduce the time complexity from `O(n) to O(log(n))`

# Some notes on BSTs
- Preforming [[🟩1.1 @ Binary Trees Traversals#Inorder LDR Traversal| inorder traversal]] on BSTs produces a sorted list
- While solving problems on BSTs, only the intermediate step (processing root data) changes
- BSTs consider either left or right subtrees for searching but not both 
- Adding an element to a BST -->  adding an element to one of its leaves

# Functions (By me)
# Binary search tree `insertion`
- **Recursive:**	
	```c
	int insert(BST *B , element e)
	{
		if(*B == NULL)
		{
			*B = Construct(e, NULL, NULL);
			return 1;
		}
	  
		if(e == (*B)->data)
			return 0;
	  
		if(e < (*B)->data)
			return insert((*B)->left, e);
		else if(e > (*B)->data)
			return insert((*B)->right, e);
		return 0;
	}
	```
- **Iterative:**
	```c
	int insert(BST *B , element e)
	{
	    while(*B)
	    {
	        if(e == (*B)->data)
	            return 0;
	        else if(e < (*B)->data)
	            B = &((*B)->left);
	        else if(e > (*B)->data)
	            B = &((*B)->right);
	    }
	
	    *B = Construct(e, NULL, NULL);
	    return 1;
	}
	```