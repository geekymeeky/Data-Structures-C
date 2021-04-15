#include<stdio.h>
#define SIZE 10
typedef struct{
	int front;
	int rear;
	int data[SIZE];
}QUEUE;

/* Function to insert an element in a circular queue */
int enqueue(QUEUE *queue, int item){
	// Overflow Condition
	if(isFull(queue))
		return -1;
	// Insertion as first element
	if(isEmpty(queue)){
		queue->data[++(queue->rear)]= item;
		++(queue->front);
	}
	// If queue is not full but rear points to the last element
	else if((queue->rear) == SIZE-1 && (!isFull(queue))){
		queue->rear = 0;
		queue->data[queue->rear] = item;
	}
	// otherwise
	else
		queue->data[++(queue->rear)] = item;
	// Returns 1 if enqueue is succesfull
	return 1;
}

int isFull(QUEUE *queue){
	// Returns True if queue is full
	return ((queue->rear == SIZE-1) && ((queue->front) == 0));
}

int isEmpty(QUEUE *queue) {
	// Returns True if queue is empty
	return (queue->front == -1);
}

/* Function to delete a element from a circular queue */
int dequeue(QUEUE *queue){
	int item;
	
	// Checking Underflow Condition
	if(isEmpty(queue))
		return -1;
		
	// Storing value of the item to be deleted	
	item = queue->data[queue->front];
	
	// If the queue has only one element
	if((queue->front) == (queue->rear)){
		queue->front = -1;
		queue->rear = -1;
	}
	
	// If the deleted element is the last element
	else if(queue->front == SIZE-1)
		queue->front = 0;
		
	// otherwise
	else
		++(queue->front);
		
	// Return deleted item
	return item;
}

/* Function display elements of a circular queue */
void traverse(QUEUE *queue){
	int i;
	if(isEmpty(queue)){
		printf("Queue is empty");
		return;
	}
	if((queue->rear) >= (queue->front)){
		for(i=(queue->front); i<=(queue->rear); i++){
			printf("%d ", queue->data[i]);
		}
	}
	else{
		for(i = (queue->front); i < SIZE; i++){
			printf("%d ", queue->data[i]);
		}
		for(i=0; i <= (queue->rear); i++){
			printf("%d ", queue->data[i]);
		}
	}
}

int main()
{
	int element, i, n;
	QUEUE queue;
	queue.front = -1;
	queue.rear = -1;
	for(i=0; i < SIZE; i++){
		printf("Enter element: %d: ", i+1);
		scanf("%d", &element);
		enqueue(&queue, element);
	}
	printf("The elements in the queue are as follows:\n");
	traverse(&queue);
	printf("\nEnter the number of times you want to dequeue: ");
	scanf("%d", &n);
	for(i=0; i<n; i++){
		element = dequeue(&queue);
		printf("\nDeleted element: %d", element);
	}
	printf("\nThe elements in the queue are as follows:\n");
	traverse(&queue);
	return 0;
}
