#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// PUSH operation
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = top;
    top = newNode;

    printf("Inserted: %d\n", value);
}

// POP operation
void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }

    struct Node* temp = top;
    printf("Deleted: %d\n", top->data);

    top = top->next;
    free(temp);
}

// PEEK operation
void peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Top element: %d\n", top->data);
    }
}

// DISPLAY operation
void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    struct Node* temp = top;

    printf("Stack elements:\n");
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
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
