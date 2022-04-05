#include <stdio.h>
#include <cstdlib>

#pragma warning(disable : 4996)

typedef struct node {
    long long value;
    struct node* next;
}node;

typedef struct Queue {
    struct node* first;
    struct node* last;
} Queue;

void init(Queue* q) {
    q->first = NULL;
    q->last = NULL;
}

void push(Queue* Q, long long x) {
    node* tmp = (node*)malloc(sizeof(node));
    tmp->value = x;
    tmp->next = NULL;
    if (Q->last) {
        Q->last->next = tmp;
    }
    Q->last = tmp;
    if (Q->first == NULL) {
        Q->first = Q->last;
    }
}

int pop(Queue* Q) {
    node* tmp = Q->first;
    if (tmp == NULL) {
        printf("null");
        return 0;
    }
    long long x = tmp->value;
    Q->first = tmp->next;
    if (Q->first == NULL) {
        Q->last = NULL;
    }
    free(tmp);
    return x;
}

int get_first(Queue* Q) {
    if (Q->first == NULL) {
        printf("null");
        return 0;
    }
    return Q->first->value;
}

int get_last(Queue* Q) {
    if (Q->last == NULL) {
        printf("null");
        return 0;
    }
    return Q->last->value;
}

int isEmpty(Queue* Q) {
    return Q->first == NULL;
}

int main() {
    Queue *q;
    q = (Queue*)malloc(sizeof(Queue*));
    init(q);
}