#include<stdio.h>
#include<malloc.h>

struct node{
	int data;
	struct node *next;
};

void push(struct node **tos, int data){
	struct node *new1 = (struct node *)malloc(sizeof(struct node));
	if(new1 == NULL)
	{
		printf("\nUnable to allocate memory\n");
		return;
	}
	new1->data = data;
	new1->next = (*tos);
	(*tos) = new1;
}

int pop(struct node **tos){
	struct node *ptr;
	int item;
	if((*tos) == NULL)
	{
		printf("\nStack is empty.");
		return -1;
	}
	item = (*tos)->data;
	ptr = (*tos);
	(*tos) = ptr->next;
	free(ptr);
	return item;
}

void peek(struct node **tos){
	if((*tos) == NULL)
	{
		printf("Stack is empty.");
		return;
	}
	else
	{
		printf("\nTOS: %d", (*tos)->data);
	}
}


void menu()
{
	printf("Enter your Choice:");
	printf("\n1. Push");
	printf("\n2. Pop");
	printf("\n3. Peek");
	printf("\nq. Quit");
}

int main()
{
	struct node *stack = NULL;
	char ch;
	int data, popped;
	menu();
	while(1)
	{
		printf("\nInput m for menu\nEnter your choice:\n");
		ch = getchar();
		switch(ch)
		{
			case '1':
				printf("\nEnter the item that you want to push: ");
				scanf("%d", &data);
				push(&stack, data);
				break;
			case '2':
				popped = pop(&stack);
				printf("Popped Item: %d", popped);
				break;
			case '3':
				peek(&stack);
				break;
			case 'm':
				menu();
				break;
			default:
				printf("Invalid choice!");
		}
		fflush(stdin);
		if(ch == 'q')
			break;
	}
	return 0;
}

