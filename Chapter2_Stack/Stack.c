#include <stdio.h>
#define MAX_STACK_SIZE 100

int stack[MAX_STACK_SIZE];
int top = -1;

int isEmpty();
int isFull();
void push(int value);
int pop();
void printAllValue();

int main(void)
{
	push(1);
	push(2);
	push(3);
	printAllValue();
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	
}

int isEmpty()
{
	if (top < 0)
	{
		return 1; //Empty
	}
	else
	{
		return 0; //!Empty
	}
}

int isFull()
{
	if (top > MAX_STACK_SIZE-1)
	{
		return 1; //Full
	}
	else
	{
		return 0; //!Full
	}
}

void push(int value)
{
	if(isFull() == 1)
	{
		printf("Stack Is Full\n");
	}
	else
	{
		stack[++top] = value;	
	}
}

int pop()
{
	if (isEmpty() == 1)
	{
		printf("Stack Is Empty\n");
		return -1;
	}
	else
	{
		return stack[top--];	
	}
}

void printAllValue()
{
	if(isEmpty() == 1)
	{
		printf("Stack Is Empty\n");
	}
	else
	{
		for(int i = 0; i <= top; i++)
		{
			printf("%d ", stack[i]);
		}
		printf("\n");
	}
}