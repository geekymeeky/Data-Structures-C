#include<stdio.h>
#define MAX_SIZE 30
int size = MAX_SIZE;
int n_node;
int status[MAX_SIZE];

typedef struct{
	int data[100];
	int front, rear;
}QUEUE;


int isFull(QUEUE *queue){
	// Returns True when queue is full
	return ((queue->rear) == size-1) && ((queue->front) == 0);
}

int isEmpty(QUEUE *queue){
	return ((queue->front) == -1);
}

int enqueue(QUEUE *queue, int item){
	// Overflow condition
	if(isFull(queue)){
		printf("Overflow!");
		return -1;
	}
	if(isEmpty(queue)){
		queue->data[++(queue->rear)] = item;
		++(queue->front);
	}
	else if((queue->rear) == size-1 && (!isFull(queue))){
		queue->rear = 0;
		queue->data[queue->rear] = item;
	}
	else{
		queue->data[++(queue->rear)] = item;
	}
	return 1;
}

int dequeue(QUEUE *queue){
	int item;
	
	if(isEmpty(queue)){
		return -1;
	}
	item = queue->data[queue->front];
	if((queue->front) == (queue->rear)){
		queue->front = -1;
		queue->rear = -1;
	}
	else if((queue->front) == size-1){
		queue->front = 0;
	}
	else{
		++(queue->front);
	}
	return item;
}

void init(int adj[][MAX_SIZE]){
	/* Initialises a null matrix */
	int i, j;
	for(i=0; i<n_node; i++){
		for(j=0; j<n_node; j++){
			adj[i][j] = 0;
		}
	}
	
	/* Initialises status of each node to 1 */
	for(i=0; i<n_node; i++){
		status[i] = 1;
	}
}

void get_adj(int adj[][MAX_SIZE]){
	int i, n_neighbours, neighbour, j;
	for(i=1; i<=n_node; i++){
		printf("Enter no. of neighbours of %d :", i);
		scanf("%d", &n_neighbours);
		for(j=1; j<=n_neighbours; j++){
			printf("Enter neighbours of %d: ", i);
			scanf("%d", &neighbour);
			if(neighbour > n_node || neighbour <1){
				printf("Invalid input");
				continue;
			}
			else{
				adj[i-1][neighbour-1] = 1;
			}
		}
	}
}

void print_mat(int adj[][MAX_SIZE]){
	int i, j;
	printf("\n---------------");
	printf("\nAdjacency Matrix:\n");
	printf("---------------\n\n");
	for(i=0; i<n_node; i++){
		for(j=0; j<n_node; j++){
			printf("%d ", adj[i][j]);
		}
		printf("\n");
	}
}

void print_status(){
	int i;
	printf("\n\n----------------");
	printf("\nVertex\tStatus\n");
	printf("----------------\n");
	for(i=0; i<n_node; i++){
		printf("%d\t%d\n", i+1, status[i]);
	}
}

void bfs(int adj[][MAX_SIZE]){
	QUEUE queue;
	int i, vertex=1, dequeued;
	queue.front = -1;
	queue.rear = -1;
	enqueue(&queue, vertex);
	status[vertex-1] = 2;
	printf("\n---------------");
	printf("\nBFS traversal:\n");
	printf("---------------\n\n");
	do{
		for(i=0; i<n_node; i++){
			if((adj[vertex-1][i] == 1) && (status[i] == 1)){
				enqueue(&queue, i+1); // Add the element no.
				status[i] = 2;
			}
		}
		dequeued = dequeue(&queue); // Adding the idx
		status[dequeued-1] = 3;
		printf("%d ", dequeued);
		vertex = queue.data[queue.front];
	}while(!isEmpty(&queue));
}

int main(){
	int adj_mat[MAX_SIZE][MAX_SIZE];
	printf("Enter no. of nodes: ");
	scanf("%d", &n_node);
	init(adj_mat);
	get_adj(adj_mat);
	print_mat(adj_mat);
	bfs(adj_mat);
	print_status();
}
