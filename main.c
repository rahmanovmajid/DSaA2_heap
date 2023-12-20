#include "heap.h"

int main(){
    Heap *heap = HEAP_new(5);

    HEAP_add(heap, 10);
    HEAP_add(heap, 6);
    HEAP_add(heap, 2);
    HEAP_add(heap, 9);
    HEAP_add(heap, 4);
    HEAP_add(heap, 8);
    HEAP_add(heap, 50);
    HEAP_add(heap, 75);
    HEAP_add(heap, 62);
    HEAP_add(heap, 27);
    HEAP_add(heap, 100);

    HEAP_printArr(heap);

    // printf("%d\n", HEAP_remove(heap));

    // HEAP_print(heap);

    // printf("%d\n", HEAP_remove(heap));

    // HEAP_print(heap);

    int size = heap->size;
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d\n", HEAP_remove(heap));
    }

    HEAP_printArr(heap);





    return 0;
}