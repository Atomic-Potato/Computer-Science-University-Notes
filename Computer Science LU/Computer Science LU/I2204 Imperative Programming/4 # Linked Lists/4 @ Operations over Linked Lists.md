# InsertNth();
```c
void InsertNth(struct node** headRef, int index, int data)
{
	if(index<0 || index >0 && *headRef == NULL) 
		printf("Error index put of range");
	else if(index == 0)
		Push(headRef, data); //base case is Push
	else
		InsertNth(&((*head)->next), index-1, data);
}
```

There are other but they are not shown in the course.