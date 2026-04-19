#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// ENQUEUE
void enqueue(int value) {
    // Check overflow
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1) {  
        front = rear = 0;
    } 
    else if (rear == MAX - 1) {
        rear = 0;   // circular condition
    } 
    else {
        rear++;
    }

    queue[rear] = value;
    printf("Inserted: %d\n", value);
}

// DEQUEUE
void dequeue() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted: %d\n", queue[front]);

    if (front == rear) {
        front = rear = -1;   // queue becomes empty
    } 
    else if (front == MAX - 1) {
        front = 0;   // circular condition
    } 
    else {
        front++;
    }
}

// DISPLAY
void display() {
    int i;

    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue elements: ");
    i = front;

    while (1) {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        if (i == MAX - 1)
            i = 0;
        else
            i++;
    }

    printf("\n");
}

// MAIN MENU
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
