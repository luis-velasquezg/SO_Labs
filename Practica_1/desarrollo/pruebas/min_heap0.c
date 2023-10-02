#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 100

// Estructura de Min-Heap
typedef struct {
    int *arr;
    int size;
    int capacity;
} MinHeap;

// Función para crear un Min-Heap vacío
MinHeap *createMinHeap(int capacity) {
    MinHeap *heap = (MinHeap *)malloc(sizeof(MinHeap));
    if (!heap) {
        perror("Error al asignar memoria");
        exit(1);
    }

    heap->arr = (int *)malloc(capacity * sizeof(int));
    if (!heap->arr) {
        perror("Error al asignar memoria");
        exit(1);
    }

    heap->size = 0;
    heap->capacity = capacity;

    return heap;
}

// Función para intercambiar dos elementos en el Min-Heap
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Función para mantener la propiedad de Min-Heap hacia arriba
void heapifyUp(MinHeap *heap, int index) {
    while (index > 0 && heap->arr[index] < heap->arr[(index - 1) / 2]) {
        swap(&heap->arr[index], &heap->arr[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

// Función para insertar un elemento en el Min-Heap
void insert(MinHeap *heap, int key) {
    if (heap->size >= heap->capacity) {
        printf("El Min-Heap está lleno, no se puede insertar más elementos.\n");
        return;
    }

    heap->arr[heap->size] = key;
    heap->size++;

    heapifyUp(heap, heap->size - 1);
}

// Función para mantener la propiedad de Min-Heap hacia abajo
void heapifyDown(MinHeap *heap, int index) {
    int smallest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < heap->size && heap->arr[leftChild] < heap->arr[smallest]) {
        smallest = leftChild;
    }

    if (rightChild < heap->size && heap->arr[rightChild] < heap->arr[smallest]) {
        smallest = rightChild;
    }

    if (smallest != index) {
        swap(&heap->arr[index], &heap->arr[smallest]);
        heapifyDown(heap, smallest);
    }
}

// Función para extraer el elemento mínimo del Min-Heap
int extractMin(MinHeap *heap) {
    if (heap->size <= 0) {
        printf("El Min-Heap está vacío.\n");
        return -1;
    }

    if (heap->size == 1) {
        heap->size--;
        return heap->arr[0];
    }

    int root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;

    heapifyDown(heap, 0);

    return root;
}

int main() {
    MinHeap *heap = createMinHeap(MAX_HEAP_SIZE);

    insert(heap, 3);
    insert(heap, 2);
    insert(heap, 1);
    insert(heap, 5);
    insert(heap, 4);

    for (int i = 0; i < heap->capacity; i++)
    {
      printf("|%d|", heap->arr[i]);
    }
     
    

    printf("Elemento mínimo extraído: %d\n", extractMin(heap));
    printf("Elemento mínimo extraído: %d\n", extractMin(heap));

    free(heap->arr);
    free(heap);

    return 0;
}
