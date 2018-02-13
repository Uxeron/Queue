/* 4 gr. 2 pogr. 226 */

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

    queue* newQueue();					/* Create a new queue */
    int enqueue(queue* que, int val);	/* Add an element to the queue. return codes: 0 - command successful, 1 - unable to allocate memory */
    int dequeue(queue* que);			/* Remove the first element in the queue. return codes: 0 - command successful, 1 - queue is empty */
    int full(queue* que);				/* Check if queue is full. return codes: 0 - not full, 1 - full */
    int empty(queue* que);				/* Check if queue is empty. return codes: 0 - not empty, 1 - empty */
    int first(queue* que);				/* Return first element value */
    int count(queue* que);				/* Return number of elements in queue*/
    void erase(queue** que);			/* Erase the entire queue */
#endif
