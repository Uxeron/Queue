#include <stdlib.h>
#include "Queue.h"

queue* newQueue() {
    queue* newQ = (queue*) malloc(sizeof(queue));
    (*newQ).size = 0;
    return newQ;
}

int enqueue(queue* que, int val) {
    node* newNode = (node*) malloc(sizeof(node));
    if(!newNode)
        return 1;

    if((*que).size > 0) {
        (*(*que).tail).next = newNode;
    }
    (*newNode).value = val;
    (*newNode).next = NULL;
    (*que).tail = newNode;
    if(empty(que))
        (*que).head = (*que).tail;
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
    return (*que).size == 0;
}

int first(queue* que) {
    return (*(*que).head).value;
}

int count(queue* que) {
    return (*que).size;
}

void erase(queue** que) {
    if(count(*que) == 1) {
        dequeue(*que);
    }

    if(empty(*que)) {
        free(*que);
        *que = NULL;
        return;
    }

    node* node1 = (**que).head;
    node* node2 = (*node1).next;

    while(node1) {
        free(node1);
        node1 = node2;
        if(node2)
            node2 = (*node2).next;
    }

    free(*que);
    *que = NULL;
}
