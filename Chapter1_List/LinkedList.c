#include <stdio.h>
#include <stdlib.h>

typedef struct Node_
{
	int data;
	struct Node_ *next;
} Node;

Node* CreateNode(int data)
{
	Node* p = (Node*)malloc(sizeof(Node));
	
	p->data = data;
	p->next = NULL;
	
	return p;
}

void appendNode(Node* p, int data)
{
	while(p->next != NULL)
	{
		p = p->next;
	}
	
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = NULL;
	
	p->next = new_node;
}

void printNode(Node* p)
{
	while(p != NULL)
	{
		printf("%d ", p->data);
		p = p -> next;
	}
	
	printf("\n");
}

void deleteAllNode(Node *p)
{
	Node* current = p;
	Node* p_prev;
	while(p != NULL)
	{
		p_prev = p -> next;
		free(p);
		p = p_prev;
	}
}

int main(void)
{
	Node* NewNode = NULL;
	NewNode = CreateNode(1);
	appendNode(NewNode, 2);
	printNode(NewNode);
	deleteAllNode(NewNode);
	
	return 0;
}
