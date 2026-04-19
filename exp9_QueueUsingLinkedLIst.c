#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

// ENQUEUE operation
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {   // Empty queue
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("Inserted: %d\n", value);
}

// DEQUEUE operation
void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    struct Node* temp = front;
    printf("Deleted: %d\n", front->data);

    front = front->next;

    if (front == NULL) {   // Queue becomes empty
        rear = NULL;
    }

    free(temp);
}

// DISPLAY operation
void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* temp = front;

    printf("Queue elements:\n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// MAIN MENU
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
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
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
