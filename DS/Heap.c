#include <stdio.h>
#include <stdbool.h>

#define MAX_ENTRY 10
typedef struct _list {
    int count;
    int entry[MAX_ENTRY];
} List;

void insertHeap(int current, int low, int high, List *list)
{
    int large = 2*low + 1;
    while (large <= high) {
        if (large < high && list->entry[large] < list->entry[large+1]) 
                            large++;
        if (current >= list->entry[large])
            break;
        else {
            list->entry[low] = list->entry[large];
            low = large;
            large = 2*low + 1;
        }
    }
    list->entry[low] = current;
}

void BuildHeap(List *list)
{
    for (int low = list->count/2 -1; low >= 0; low--)
    {
        insertHeap(list->entry[low], low, list->count, list);
    }
}

void heapSort(List *list)
{
    int current;
    int lu;

    BuildHeap(list);
    for (lu = list->count -1; lu >=1; lu--) {
        current = list->entry[lu];
        list->entry[lu] = list->entry[0];
        insertHeap(current, 0, lu -1, list);
    }
}

int main()
{
    List list;

    list.count = 7;
    //list.entry[list.count] = { 5, 3, 6, 2, 7, 9, 1 };
    list.entry[0] = 5; 
    list.entry[1] = 3; 
    list.entry[2] = 6; 
    list.entry[3] = 2; 
    list.entry[4] = 7; 
    list.entry[5] = 9; 
    list.entry[6] = 1; 

    for (int i=0; i < list.count; i++)
    {
        printf(" %d ", list.entry[i]);
    }
    heapSort(&list);
    for (int i=0; i < list.count; i++)
    {
        printf(" %d ", list.entry[i]);
    }
}


