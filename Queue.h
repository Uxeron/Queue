#ifndef QUEUE_H_
    #define QUEUE_H_

    typedef struct node {
        int value;
        node* next;
    } node;

    typedef struct queue {
        node* head;
        node* tail;
        int size = 0;
    } queue;

    queue* newQueue();
    int enqueue(queue* que, int val);
    int dequeue(queue* que);
    int full(queue* que);
    int empty(queue* que);
    int first(queue* que);
    int count(queue* que);
    void clear(queue* que);
#endif
