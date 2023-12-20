#include "heap.h"

Heap *HEAP_new(int capacity)
{
    Heap *newHeap = (Heap *)malloc(sizeof(Heap));

    newHeap->arrSize = capacity;
    newHeap->capacity = newHeap->size = 0;

    newHeap->arr = (int *)calloc(newHeap->arrSize, sizeof(int));

    return newHeap;
}

void HEAP_printArr(Heap *heap)
{
    if (heap == NULL || heap->arrSize == 0)
        return;
    if (heap->size == 0)
    {
        puts("Empty heap!");
    }
    int i;
    for (i = 0; i < heap->arrSize; i++)
    {
        printf("%d ", heap->arr[i]);
    }
    puts("");
}

void HEAP_resizeUp(Heap *heap, int newCapacity)
{
    int *newArr = (int *)calloc(heap->arrSize + newCapacity, sizeof(int));
    int i = 0;
    for (; i < heap->capacity; i++)
    {
        newArr[i] = heap->arr[i];
    }
    heap->arrSize += newCapacity;
    free(heap->arr);
    heap->arr = newArr;
}

int HEAP_isEmpty(Heap *heap)
{
    return (heap->size == 0 || heap->arr == NULL) ? 1 : 0;
}

int HEAP_peek(Heap *heap)
{
    if (HEAP_isEmpty(heap))
    {
        puts("Empty heap!");
        return -1; //if all the values are non-negative
    }
    return heap->arr[0];
}

void HEAP_add(Heap *heap, int value)
{
    if (heap == NULL || heap->arr == NULL)
        return;

    if (heap->size >= heap->arrSize)
    { //overflow
        HEAP_resizeUp(heap, heap->arrSize);
    }

    heap->arr[heap->size++] = value; //add value to the end(first available node) of the heap
    heap->capacity = heap->size;     //in add heap capacity increases with heap size

    //adjust up to check and fix heap properties if violated
    HEAP_maxAdjustUp(heap, heap->size - 1);
}

int HEAP_remove(Heap *heap)
{
    if (heap == NULL || heap->arr == NULL)
        return -1;

    if (HEAP_isEmpty(heap))
        return -1; //if all the values are non-negative

    int retVal = heap->arr[0];
    heap->size--; //remove value to the end(first available node) of the heap
    heap->arr[0] = heap->arr[heap->size];
    heap->arr[heap->size] = retVal;

    //adjust down starting from the root
    HEAP_maxAdjustDown(heap, 0);

    return retVal;
}

void HEAP_maxAdjustUp(Heap *heap, int index)
{
    int temp;// = heap->arr[index];
    int parentIdx;
    while (index > 0)
    {
        parentIdx = (index - 1) / 2;
        // printf("\t%d %d", index, heap->arr[index]);
        // printf("\t%d %d\n", parentIdx, heap->arr[parentIdx]);
        if (heap->arr[parentIdx] < heap->arr[index])
        {
            temp = heap->arr[parentIdx];
            heap->arr[parentIdx] = heap->arr[index];
            heap->arr[index] = temp;
            index = parentIdx;
        }
        else
        {
            break;
        }
    }
}

void HEAP_maxAdjustDown(Heap *heap, int index)
{
    int temp;
    while (index < heap->size)
    {
        int lIdx = 2 * index + 1;
        int rIdx = 2 * index + 2;
        int maxIdx = index;

        // printf("\t%d %d", index, heap->arr[index]);
        // printf("\t%d %d", lIdx, heap->arr[lIdx]);
        // printf("\t%d %d\n", rIdx, heap->arr[rIdx]);

        if (lIdx < heap->size && heap->arr[lIdx] > heap->arr[maxIdx])
            maxIdx = lIdx;

        if (rIdx < heap->size && heap->arr[rIdx] > heap->arr[maxIdx])
            maxIdx = rIdx;

        if (maxIdx > index)
        {
            temp = heap->arr[maxIdx];
            heap->arr[maxIdx] = heap->arr[index];
            heap->arr[index] = temp;
            index = maxIdx;
        }
        else
        {
            break;
        }
    }
}
