#include<stdio.h>
#include <cstdlib>

#pragma warning( disable: 4996 )


typedef struct Stack {
    int data;
    struct Stack* next;

}Stack;

void push(Stack **top, int data) {
    Stack* temp;
    temp = (Stack*)malloc(sizeof(Stack));
    temp->data = data;
    temp->next = *top;
    *top = temp;
}

int pop(Stack **top) {
    Stack* temp = *top;
    int val;
    if (*top == NULL) {
        exit(-1);
    }
    else {
        val = temp->data;
        *top = temp->next;
        free(temp);
        return val;
    }



}

int top(Stack **top) {
    Stack* temp = *top;
    if (*top != NULL) {
        return temp->data;
    }
    else {
        exit(-1);
    }
}

int isEmpty(Stack **top) {
    return *top == NULL;
}



int main() {
    Stack *elem = NULL;
    Stack* ind = NULL;

}