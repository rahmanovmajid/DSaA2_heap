#ifndef _HEAP__
#define _HEAP__

#include <stdio.h>
#include <stdlib.h>


typedef struct heap{
    int capacity; //capacity of the heap
    int size;     //size of the heap //index to be inserted
    int arrSize;  //size of the physical table
    int *arr;     //table that holds nodes
}Heap;



Heap *HEAP_new(int capacity);
void HEAP_printArr(Heap *heap);
void HEAP_resizeUp(Heap *heap, int newCapacity);   //increase the capacity
void HEAP_resizeDown(Heap *heap, int newCapacity); //decrease the capacity //HW

int HEAP_isEmpty(Heap *heap);
int HEAP_peek(Heap *heap);
void HEAP_add(Heap *heap, int value);
int HEAP_remove(Heap *heap);

void HEAP_maxAdjustUp(Heap *heap, int index);
void HEAP_maxAdjustDown(Heap *heap, int index);
Heap *HEAP_maxHeapify(int *array); //HW





#endif