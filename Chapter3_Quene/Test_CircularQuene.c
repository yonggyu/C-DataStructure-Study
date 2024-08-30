#include "CircularQuene.h"

int main(void)
{
    int i;
    CircularQuene* Quene;

    CQ_CreateQuene(&Quene, 10);

    CQ_Enquene(Quene, 1);
    CQ_Enquene(Quene, 2);
    CQ_Enquene(Quene, 3);
    CQ_Enquene(Quene, 4);
    
    for(i = 0; i < 3; i++)
    {
        printf("Dequene: %d, ", CQ_Dequene(Quene));
        printf("Front:%d, Rear:%d\n", Quene->Front, Quene->Rear);
    }

    i = 100;
    while(CQ_IsFull(Quene) == 0)
    {
        CQ_Enquene(Quene, i++);
    }

    printf("Capacity: %d, Size: %d\n\n", Quene->Capacity, CQ_GetSize(Quene));

    while(CQ_IsEmpty(Quene) == 0)
    {
        printf("Dequene: %d, ", CQ_Dequene(Quene));
        printf("Front:%d, Rear:%d\n", Quene->Front, Quene->Rear);
    }

    CQ_DestroyQuene(Quene);

    return 0;
}