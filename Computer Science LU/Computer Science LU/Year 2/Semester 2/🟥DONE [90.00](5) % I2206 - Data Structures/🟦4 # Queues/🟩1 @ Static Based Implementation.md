We will use a circular array for this one with 2 indices one for the `front` and one for the `read` plus an empty cell to mark the beginning and end of the circular array
![[Pasted image 20220616132543.png]]
So if:
- Front = Rear + 1 then the queue is empty
- Front = Rear + 2 then the queue is full


**`Type_Queue.h`**
```c
#define N 69

typedef int element;
typedef struct
{
	element data[N];
	int front;
	int rear;
}*queue;
```

**`Queue.h`**
```c
#include "Type_Queue.h"

extern queue CreateQueue();
extern int EnQueue(queue* q, element e);
extern int DeQueue(quque* q);
extern int Front(queue q, element* e);
extern int isEmptyQueue(quque q);
extern int isFullQueue(queue q);
```

**`Queue.c`**
```c
#include "Queue.h"

queue CreateQueue()
{
	queue q;
	q.front = 1;
	q.rear = 0;
	return q;
}

int EnQueue(queue* q, element e)
{
	if(isFullQueue(*q))
		return 0;

	q->rear = (q->rear + 1) % N;
	q->data[q->rear] = e;

	return 1;
}

int DeQueue(quque* q)
{
	if(isEmptyQueue(*q))
		return 0;

	q->front = (q->front + 1) % N;

	return 1;
}

int Front(queue q, element* e)
{
	if(isEmptyQueue(q))
		return 0;

	*e = q.data[q.front];

	return 1;
}

int isEmptyQueue(quque q)
{
	return q.front == (q.rear+1) % N;
}

int isFullQueue(queue q)
{
	return q.front == (q.rear+2) % N;
}
```


# Why we used `% N` to increment?
In division we have a `quotient * N + remainder` and since N is always greater than the cell we are moving into the quotient will always be 0 and the remainder will be equal to the cell we move into.
However when we reach the cell that is equal to N (which is out of the array) then the quotient will be `1` and the remainder `0` thus taking us back to the first cell of the array.

# Notes
- The dummy cell is not static, and as you notice it doesnt exist, we just know using `rear+1` and `rear+2`