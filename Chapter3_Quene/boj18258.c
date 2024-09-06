#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 백준.18258 큐 2

typedef struct Quene
{
    int data[2000000];
    int front;
    int rear;
} Quene;

void CreateQuene(Quene* q)
{
    q->front = q -> rear = -1;
}

int is_empty(Quene* q)
{
    return (q->front == q->rear);
}

int size(Quene* q)
{
    if(is_empty(q)) {
        return 0;
    }

    return (q->rear - q->front);
}

void push(Quene* q, int data)
{
    q->data[++(q->rear)] = data;
}

int pop(Quene* q)
{
    if(is_empty(q))
    {
        return -1;
    }

    return q->data[++(q->front)];
}

int front(Quene* q)
{
    if(is_empty(q))
    {
        return -1;
    }
    else
    {
        return q->data[q->front + 1];
    }
}

int back(Quene* q)
{
    if(is_empty(q))
    {
        return -1;
    }
    else
    {
        return q->data[q->rear];
    }
}

int main(void)
{
    Quene q;
    
    CreateQuene(&q);

    int N;
    scanf("%d", &N);
    while(N--)
    {
        char x[6];
        scanf("%s", x);

        if(!strcmp(x, "push"))
        {
            int data;
            scanf("%d", &data);
            push(&q, data);
        }
        
        else if(!strcmp(x, "pop"))
        {
            printf("%d\n", pop(&q));
        }
        else if(!strcmp(x, "size"))
        {
            printf("%d\n", size(&q));
        }
        else if(!strcmp(x, "empty"))
        {
            printf("%d\n", is_empty(&q));
        }
        else if(!strcmp(x, "front"))
        {
            printf("%d\n", front(&q));
        }
        else if(!strcmp(x, "back"))
        {
            printf("%d\n", back(&q));
        }
    }
    return 0;
}