#include <stdlib.h>

int compare(const void *a, const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (num1 < num2)
        return -1;
    
    if (num1 > num2)
        return 1;
    
    return 0;
}

int lastStoneWeight(int* stones, int stonesSize){

    int weight = 0;
    
    int last = stonesSize - 1;
    int start = last - 1;
    
    qsort(stones, stonesSize, sizeof(int), compare);
    
    for(int i = stonesSize - 1;i > 0;i--)
    {
        if (stones[last] == stones[start])
        {
            stones[last] = 0;
            stones[start] = 0;
        }
        else
        {
            stones[last] = stones[last] - stones[start];
            stones[start] = 0;
        }
        qsort(stones, stonesSize, sizeof(int), compare);
    }
    
    for(int i = 0;i < stonesSize;i++)
    {
        if (stones[i] == 0)
            continue;
        else
        {
            weight = stones[i];
            break;
        }
    }
    return weight;
}
