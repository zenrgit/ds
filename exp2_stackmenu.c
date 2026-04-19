#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;

// Function declarations
void push();
void pop();
void peek();
void display();

int main() {
    int choice;

    do {
        printf("\n------ STACK MENU ------\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEK\n");
        printf("4. DISPLAY\n");
        printf("5. EXIT\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
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
                printf("Exiting Program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}

// PUSH operation
void push() {
    int item;

    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
    } else {
        printf("Enter element: ");
        scanf("%d", &item);

        top++;
        stack[top] = item;

        printf("Element pushed successfully\n");
    }
}

// POP operation
void pop() {
    if (top == -1) {
        printf("Stack is empty (Underflow)\n");
    } else {
        printf("Popped element: %d\n", stack[top]);
        top = top - 1;
    }
}

// PEEK operation
void peek() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Top element is: %d\n", stack[top]);
    }
}

// DISPLAY operation
void display() {
    int i;

    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements:\n");
        for (i = top; i >= 0; i--) {
            printf("%d\t", stack[i]);
        }
    }
    printf("\n");
}
