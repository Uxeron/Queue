#include <stdlib.h>
//#include <stdio.h>

typedef struct node {
    int value;
    node* next;
} node;

typedef struct queue {
    node* head;
    node* tail;
    int size = 0;
} queue;

queue* newQueue() {
    return (queue*) malloc(sizeof(queue));
}

int enqueue(queue* que, int val) {
    node* newNode = (node*) malloc(sizeof(node));
    if(!newNode)
        return 1;

    if((*que).size > 0) {
        (*(*que).tail).next = newNode;
    }
    (*newNode).value = val;
    (*que).tail = newNode;
    (*que).size += 1;
    return 0;
}

int dequeue(queue* que) {
    if((*que).size == 0)
        return 1;

    node* tmpNode = (*que).head;
    (*que).size -= 1;
    if((*que).size > 0) {
        (*que).head = (*(*que).head).next;
    } else {
        (*que).head = NULL;
        (*que).tail = NULL;
    }
    free(tmpNode);
    return 0;
}

int full(queue* que) {
    node* newNode = (node*) malloc(sizeof(node));
    if(!newNode) {
        return 1;
    }
    return 0;
}

int empty(queue* que) {
    return (*que).size > 0;
}

int first(queue* que) {
    return (*(*que).head).value;
}

int count(queue* que) {
    return (*que).size;
}

void clear(queue* que) {
    node* node1 = (*que).head;
    node* node2 = (*node1).next;

    while(node1) {
        free(node1);
        node1 = node2;
        node2 = (*node1).next;
    }

    free(que);
}
