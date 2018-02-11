#ifndef QUEUE_H_
    #define QUEUE_H_

    typedef struct node {
        int value;
        struct node* next;
    } node;

    typedef struct queue {
        node* head;
        node* tail;
        int size;
    } queue;

    queue* newQueue();
    int enqueue(queue* que, int val);
    int dequeue(queue* que);
    int full(queue* que);
    int empty(queue* que);
    int first(queue* que);
    int count(queue* que);
    void erase(queue** que);
#endif
