#include "CircularQuene.h"

void CQ_CreateQuene(CircularQuene** Quene, int Capacity)
{
    // '큐' 구조체를 자유 저장소에 저장
    (*Quene) = (CircularQuene*)malloc(sizeof(CircularQuene));
    
    // Capacity+1 만큼의 노드를 자유 저장소에 저장
    (*Quene)->Nodes = (Node*)malloc(sizeof(Node)*(Capacity+1));

    (*Quene)->Capacity = Capacity;
    (*Quene)->Front = 0;
    (*Quene)->Rear = 0;
}

void CQ_DestroyQuene(CircularQuene* Quene)
{
    free(Quene->Nodes);
    free(Quene);
}

void CQ_Enquene(CircularQuene* Quene, ElementType Data)
{
    int Position = 0;

    if(Quene->Rear==Quene->Capacity)
    {
        Position = Quene->Rear;
        Quene->Rear = 0;
    }
    else
        Position = Quene->Rear++;
    
    Quene->Nodes[Position].Data = Data;
}

ElementType CQ_Dequene(CircularQuene* Quene)
{
    int Position = Quene->Front;

    if(Quene->Front == Quene->Capacity)
        Quene->Front = 0;
    
    else
        Quene->Front++;
    
    return Quene->Nodes[Position].Data;
}

int CQ_GetSize(CircularQuene* Quene)
{
    if(Quene->Front <= Quene->Rear)
        return Quene->Rear - Quene->Front;
    
    else
        return Quene->Rear + (Quene->Capacity - Quene->Front) + 1;
}

int CQ_IsEmpty(CircularQuene* Quene)
{
    return (Quene->Front == Quene->Rear);
}

int CQ_IsFull(CircularQuene* Quene)
{
    if(Quene->Front < Quene->Rear)
        return (Quene->Rear - Quene->Front) == Quene->Capacity;
    
    else
        return (Quene->Rear+1) == Quene->Front;
}