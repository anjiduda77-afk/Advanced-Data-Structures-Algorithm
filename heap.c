#include <stdio.h>
int heap[50], size = 0, type;

void insert(int val) {
    int i = ++size;
    if (type == 1) { while (i > 1 && val < heap[i/2]) { heap[i] = heap[i/2]; i = i/2; } }
    else           { while (i > 1 && val > heap[i/2]) { heap[i] = heap[i/2]; i = i/2; } }
    heap[i] = val;
}

void deleteRoot() {
    int last = heap[size--], parent = 1, child = 2;
    if (type == 1) {
        while (child <= size) {
            if (child < size && heap[child] > heap[child+1]) child++;
            if (last <= heap[child]) break;
            heap[parent] = heap[child]; parent = child; child *= 2;
        }
    } else {
        while (child <= size) {
            if (child < size && heap[child] < heap[child+1]) child++;
            if (last >= heap[child]) break;
            heap[parent] = heap[child]; parent = child; child *= 2;
        }
    }
    heap[parent] = last;
}

void display() {
    if (size == 0) { printf("Heap is empty\n"); return; }
    for (int i=1; i<=size; i++) printf("%d ", heap[i]); printf("\n");
}

int main() {
    int choice, val;
    printf("1. Min Heap\n2. Max Heap\n"); scanf("%d",&type);
    while (1) {
        printf("\n1.Insert\n2.Delete Root\n3.Display\n4.Exit\n"); scanf("%d",&choice);
        switch(choice) {
            case 1: printf("Value: "); scanf("%d",&val); insert(val); break;
            case 2: deleteRoot(); break;
            case 3: display(); break;
            case 4: return 0;
        }
    }
}