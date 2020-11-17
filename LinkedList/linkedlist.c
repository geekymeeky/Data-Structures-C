#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *next;
};

void menu(void);
void create(struct node **, int);
void traverse(struct  node **);
void insertionAtBeg(struct node **, int);
void insertionAtEnd(struct node **, int);
void sort(struct node **);
void insertionAtLoc(struct node **, int, int);
void delAtBeg(struct node **);
void delAtEnd(struct node **);
void delGivenItem(struct node **, int);

void insertionAtBeg(struct node **head, int data){
	struct node *new1 = (struct node *)malloc(sizeof(struct node));
	if(new1 == NULL)
	{
		printf("\nUnable to allocate memory\n");
		return;
	}
	new1->data = data;
	new1->next = (*head);
	(*head) = new1;
}

void insertionAtEnd(struct node **head, int data){
	struct node *temp, *new1;
	new1 = (struct node *)malloc(sizeof(struct node));
	if(new1 == NULL)
	{
		printf("\nUnable to allocate memory\n");
		return;
	}
	new1->data = data;
	new1->next = NULL;
	if((*head) == NULL)
	{
		(*head) = new1;
		return;
	}
	else
	{
		temp = *head;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new1;
		return;
	}
}

void creation(struct node **head, int n)
{
	int i, data;
	for(i=0; i<n; i++)
	{
		printf("\nEnter data for node %d: ", i+1);
		scanf("%d", &data);
		insertionAtEnd(&(*head), data);
	}
}

void sort(struct node **head)
{
	struct node *current, *index;
	int temp;
	for(current = (*head); current != NULL; current=current->next){
		for(index = current->next; index != NULL; index=index->next){
			if(current->data > index->data)
			{
				temp = current->data;
				current->data = index->data;
				index->data = temp;
			}
		}
	}
}

void insertionAtLoc(struct node **head, int data, int pos)
{
	int count = 0, i;
	struct node *ptr;
	struct node *new1;
	ptr = (*head);
	while(ptr != NULL){
		count++;
		ptr = ptr->next;
	}
	if(pos == 1)
	{
		insertionAtBeg(&(*head), data);
	}
	else if(pos == count+1)
	{
		insertionAtEnd(&(*head), data);
	}
	else if(pos > 1 && pos <= count)
	{
		ptr = (*head);
		for(i=1; i<pos-1; i++)
		{
			ptr = ptr->next;
		}
		new1 = (struct node *)malloc(sizeof(struct node));
		if(new1 == NULL)
		{
			printf("\nUnable to allocate memory\n");
			return;
		}
		new1->data = data;
		new1->next = ptr->next;
		ptr->next = new1;
	}
	else{
		printf("\nInvalid Position! ");
	}
}

void delAtBeg(struct node **head){
	struct node *ptr;
	if((*head) == NULL)
	{
		printf("\nUnderflow.");
		return;
	}
	ptr = (*head);
	(*head) = ptr->next;
	free(ptr);
}

void delAtEnd(struct node **head){
	struct node *temp, *prev;
	if((*head) == NULL)
	{
		printf("\nUnderflow.");
		return;
	}
	else if(((*head)-> next) == NULL)  
        {  
            *head = NULL;  
            free((*head));  
            printf("\nOnly node of the list deleted ...");  
        }
    else  
    {  
        temp = (*head);   
        while(temp->next != NULL)  
        {  
            prev = temp;  
            temp = temp ->next;  
        }  
        prev->next = NULL;  
        free(temp);  
        printf("\n Deleted Node from the last ...");  
    }     
}  

void delGivenItem(struct node **head, int item){
 	struct node *ptr;
 	struct node *prev;
 	int found = 0;
 	if((*head) == NULL)
	{
		printf("\nUnderflow.");
		return;
	}
 	ptr = (*head);
 	prev = ptr;
    while (ptr != NULL) 
    { 
        if (ptr->data == item){
        	found =1;
        	break;
		}
        prev = ptr;
        ptr = ptr->next; 
    } 
    if(found)
    {
    	prev->next = ptr->next;
    	free(ptr);
	}
	else
	{
		printf("\nElement not found");
	}
}

void traverse(struct node **head)
{
	struct node *temp = (*head);
	if((*head) == NULL)
	{
		printf("\nList is empty\n");
	}
	else
	{
		temp = (*head);
		while(temp != NULL)
		{
			printf("%d -->", temp->data);
			temp = temp->next;
		}
	}
}

void menu()
{
	printf("Linked List :)\n");
	printf("1 -> Create a linked list\n");
	printf("2 -> Traversal\n");
	printf("3 -> Insertion at the Beginning\n");
	printf("4 -> Insertion at the End\n");
	printf("5 -> Sort the list\n");
	printf("6 -> Insertion at the given location\n");
	printf("7 -> Deletion of the first node\n");
	printf("8 -> Deletion of the last node\n");
	printf("9 -> Deletion of a given item of node\n");
}

int main()
{
	struct node *list1 = NULL;
	char ch;
	int data, n;
	menu();
	while(1)
	{
		printf("\nInput m for menu\nEnter your choice:\n");
		ch = getchar();
		switch(ch)
		{
			case '1':
				printf("Input the number of nodes you want to create: ");
				scanf("%d", &n);
				creation(&list1, n);
				break;
			case '2':
				traverse(&list1);
				break;
			case '3':
				printf("\nEnter the data that you want to insert: ");
				scanf("%d", &data);
				insertionAtBeg(&list1, data);
				break;
			case '4':
				printf("\nEnter the data that you want to insert: ");
				scanf("%d", &data);
				insertionAtEnd(&list1, data);
				break;
			case '5':
				sort(&list1);
				printf("Linked List Sorted Successfully!");
				break;
			case '6':
				printf("Enter the position where you want to insert the data: ");
				scanf("%d", &n);
				printf("\nEnter the data that you want to insert: ");
				scanf("%d", &data);
				insertionAtLoc(&list1, data, n);
				break;
			case '7':
				delAtBeg(&list1);
				printf("\nFirst Node deleted Succesfully!");
				break;
			case '8':
				delAtEnd(&list1);
				printf("\nLast Node deleted Succesfully!");
				break;
			case '9':
				printf("\nEnter the data that you want to delete from the list: ");
				scanf("%d", &data);
				delGivenItem(&list1, data);
				break;
			case 'm':
				menu();
				break;
		}
		fflush(stdin);
		if(ch == 'q')
			break;
	}
	return 0;
}
