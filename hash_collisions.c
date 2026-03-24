#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int linear[SIZE];
int quadratic[SIZE];
int doubleHash[SIZE];
struct node { int data; struct node *next; };
struct node* chain[SIZE];

int hash2(int key) { return 7 - (key % 7); }

void insertLinear(int key) {
    int index = key % SIZE, i = 0;
    while(i < SIZE && linear[index] != -1) { index = (index + 1) % SIZE; i++; }
    if(i == SIZE) printf("Linear table full\n");
    else linear[index] = key;
}

void insertQuadratic(int key) {
    int index = key % SIZE, i = 1;
    while(i < SIZE && quadratic[index] != -1) { index = (key % SIZE + i*i) % SIZE; i++; }
    if(i == SIZE) printf("Quadratic table full\n");
    else quadratic[index] = key;
}

void insertDoubleHash(int key) {
    int index = key % SIZE, step = hash2(key), i = 0;
    while(i < SIZE && doubleHash[index] != -1) { index = (index + step) % SIZE; i++; }
    if(i == SIZE) printf("Double hashing table full\n");
    else doubleHash[index] = key;
}

void insertChaining(int key) {
    int index = key % SIZE;
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = key; newNode->next = chain[index]; chain[index] = newNode;
}

void displayLinear() {
    printf("\nLinear Probing:\n");
    for(int i=0;i<SIZE;i++) linear[i]!=-1 ? printf("%d -> %d\n",i,linear[i]) : printf("%d -> Empty\n",i);
}
void displayQuadratic() {
    printf("\nQuadratic Probing:\n");
    for(int i=0;i<SIZE;i++) quadratic[i]!=-1 ? printf("%d -> %d\n",i,quadratic[i]) : printf("%d -> Empty\n",i);
}
void displayDoubleHash() {
    printf("\nDouble Hashing:\n");
    for(int i=0;i<SIZE;i++) doubleHash[i]!=-1 ? printf("%d -> %d\n",i,doubleHash[i]) : printf("%d -> Empty\n",i);
}
void displayChaining() {
    printf("\nSeparate Chaining:\n");
    for(int i=0;i<SIZE;i++) {
        struct node *temp = chain[i]; printf("%d -> ",i);
        while(temp) { printf("%d -> ",temp->data); temp=temp->next; } printf("NULL\n");
    }
}

int main() {
    int n, key;
    for(int i=0;i<SIZE;i++) { linear[i]=-1; quadratic[i]=-1; doubleHash[i]=-1; chain[i]=NULL; }
    printf("Enter number of elements: "); scanf("%d",&n);
    for(int i=0;i<n;i++) {
        printf("Enter key: "); scanf("%d",&key);
        insertLinear(key); insertQuadratic(key); insertDoubleHash(key); insertChaining(key);
    }
    displayLinear(); displayQuadratic(); displayDoubleHash(); displayChaining();
    return 0;
}