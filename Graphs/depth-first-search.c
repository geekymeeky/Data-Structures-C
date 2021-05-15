#include<stdio.h>
#define MAX_SIZE 30
int size = MAX_SIZE;
int n_node;
int status[MAX_SIZE];

typedef struct{
	int data[100];
	int top;
}STACK;

int isEmpty(STACK *stack){
	return (stack->top == -1);
}

int peek(STACK *stack){
	return (stack->data[stack->top]);
}

void push(STACK *stack, int item){
	stack->data[++(stack->top)] = item;
}

int pop(STACK *stack){
	int item;
	if(!isEmpty(stack)){
		item = stack->data[(stack->top)];
		--(stack->top);
		return item;
	}
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

void dfs(int adj[][MAX_SIZE]){
	STACK stack;
	int i, vertex=1, popped;
	stack.top = -1;
	push(&stack, vertex);
	status[vertex-1] = 2;
	printf("\n---------------");
	printf("\nDFS traversal:\n");
	printf("---------------\n\n");
	do{
		popped = pop(&stack);
		printf("%d ", popped);
		status[popped-1] = 3;
		for(i=0; i<n_node; i++){
			if((adj[popped-1][i] == 1) && (status[i] == 1)){
				push(&stack, i+1);
				status[i] = 2;
			}
		}
	}while(!isEmpty(&stack));
}

int main(){
	int adj_mat[MAX_SIZE][MAX_SIZE];
	printf("Enter no. of nodes: ");
	scanf("%d", &n_node);
	init(adj_mat);
	get_adj(adj_mat);
	print_mat(adj_mat);
	dfs(adj_mat);
	print_status();
}
