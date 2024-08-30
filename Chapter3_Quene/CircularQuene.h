#ifndef CIRCULAR_QUENE_H
#define CIRCULAR_QUENE_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{       
    ElementType Data;
}Node;

typedef struct tagCircularQuene
{
    int Capacity;
    int Front;
    int Rear;

    Node* Nodes;
} CircularQuene;

void CQ_CreateQuene(CircularQuene** Quene, int Capacity);
void CQ_DestroyQuene(CircularQuene* Quene);
void CQ_Enquene(CircularQuene* Quene, ElementType Data);
ElementType CQ_Dequene(CircularQuene* Quene);
int CQ_GetSize(CircularQuene* Quene);
int CQ_IsEmpty(CircularQuene* Quene);
int CQ_IsFull(CircularQuene* Quene);

#endif