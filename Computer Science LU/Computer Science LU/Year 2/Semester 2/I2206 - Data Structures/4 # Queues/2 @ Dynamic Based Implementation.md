For using linked lists we will also keep an address for the front of the linked list and the back of the linked list.

**`Type_Queue.h`**
```c
#define N 69

typedef int element;

typedef struct cell
{
	element data;
	struct cell* next;
};

typedef struct
{
	struct cell *front;
	struct cell *rear;
}queue;
```

**`Queue.h`**
```c
#include "Type_Queue.h"

extern queue CreateQueue();
extern int EnQueue(queue* q, element e);
extern int DeQueue(quque* q);
extern int Front(queue q, element* e);
extern int isEmptyQueue(quque q);
```

**`Queue.c`**
```c
#include "Queue.h"

queue CreateQueue()
{
	queue q;
	q.front = NULL;
	q.rear = NULL;
	return q;
}

int EnQueue(queue* q, element e)
{
	struct cell* newCell = (struct cell*)malloc(sizeof(struct cell));
	if(newCell == NULL)
		return 0;

	newCell->data = e;
	newCell->next = NUll;

	if(isEmptyQueue(*q)) 
	{
		q->front = newCell;
		q->rear = newCell;
	}
	else
	{
		q->rear->next = newCell;
		q->rear = newCell;
	}
	
	return 1;
}

int DeQueue(quque* q)
{
	if(isEmptyQueue(*q))
		return 0;
		
	struct cell* toRemove;
	toRemove = q->front;
	q->front = q->front->next;
	free(toRemove);

	if(isEmptyQueue(*q))
		q->rear = NULL;
	
	return 1;
}

int Front(queue q, element* e)
{
	if(isEmptyQueue(q))
		return 0;

	*e = q.front->data;

	return 1;
}

int isEmptyQueue(quque q)
{
	return q.front == NULL;
}
```