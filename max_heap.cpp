// using array for heap


void add_elem_heap(int heap[], int* heapSize, int elem){
    int i, parent;
    i = *heapSize;
    heap[*heapSize] = elem;
    parent = (i - 1) / 2;
    while (i > 0 && heap[parent] < heap[i]){
        int temp = heap[i];
        heap[i] = heap[parent];
        heap[parent] = temp;

        i = parent;
        parent = (i - 1) / 2;
    }
    *heapSize = *heapSize + 1;
}

void heapify(int heap[], int heapSize, int i){
    int left, right, largest;
    int temp;
    while (true){
        largest = i;
        left = 2*i+1;
        right = 2*i+2;
        if (left < heapSize && heap[left] > heap[largest]){
            largest = left;
        }
        if (right < heapSize && heap[right] > heap[largest])
        {
            largest = right;
        }

        if (largest == i)
        {
            break;
        }

        temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        i = largest;
    }
}

void heap_sort(int heap[], int heapSize){
    for (int i = heapSize / 2 - 1; i >= 0; i--)
        heapify(heap, heapSize, i);

    for (int i=heapSize-1; i>=0; i--)
    {
        swap(heap[0], heap[i]);
        heapify(heap, i, 0);
    }
}

int extract_root(int heap[], int* heapSize){
    int x;
    x = heap[0];
    heap[0] = heap[*heapSize - 1];
    *heapSize = *heapSize - 1;
    heapify(heap, 0, *heapSize);
    return x;
}