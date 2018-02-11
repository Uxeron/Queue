/* Gabrielius Vaiskunas 4 Grupe */

#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

int menu(queue** Queue);

int main() {
	int close = 0;
    queue* Queue = NULL;

	while (!close) {
		system("cls");
		close = menu(&Queue);
	}
    if(Queue)
	   erase(&Queue);
    return 0;
}

int menu(queue** Queue) {
	int selection;
	int value;
	int index;
	int retValue;
	printf("%s",
    "Select option:\n"
    "0 - Create a new queue\n"
    "1 - Enqueue an elment\n"
    "2 - Dequeue the first element\n"
    "3 - Check if queue is full\n"
    "4 - Check if queue is empty\n"
    "5 - Get first element of the queue\n"
    "6 - Get number of elements in queue\n"
    "7 - Erase queue\n"
    "8 - Exit program\n"
    "Selection: ");
	scanf("%d", &selection);
	fflush(stdin);
    if(!*Queue && selection != 0 && selection != 8) {
        printf("%s\n", "Create a queue first");
        scanf("%c", &value);
        return 0;
    }
	switch(selection) {
		case 0: *Queue = newQueue();
                if(!Queue) printf("%s\n", "Error creating queue");
                else printf("%s\n", "Queue created");
				break;
		case 1: printf("%s", "Enter value of new element: ");
				scanf("%d", &value);
				fflush(stdin);
				if (enqueue(*Queue, value)) printf("%s", "Unable to create a new element");
				else printf("%s", "New element created");
				break;
		case 2: if(dequeue(*Queue)) printf("%s\n", "Queue already empty");
                else printf("%s\n", "First element removed from queue");
                break;
        case 3: if(full(*Queue)) printf("%s\n", "Queue is full");
                else printf("%s\n", "Queue is not full");
                break;
        case 4: if(empty(*Queue)) printf("%s\n", "Queue is empty");
                else printf("%s\n", "Queue is not empty");
                break;
        case 5: if(empty(*Queue)) printf("%s\n", "Queue is empty");
                else printf("%s %d\n", "First element value is", first(*Queue));
                break;
        case 6: printf("%s %d\n", "Number of elements in queue is", count(*Queue));
                break;
        case 7: erase(Queue);
                printf("%s %d\n", "Queue erased");
                break;
        case 8: return 1;
		default: printf("%s", "Invalid selection");
				scanf("%c", &value);
				return 0;
	}
    scanf("%c", &value);
    return 0;
}
