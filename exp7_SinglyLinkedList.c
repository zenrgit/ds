#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

// Create list
void create() {
    int n, i, val;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &val);

        newnode->data = val;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
        } else {
            struct node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newnode;
        }
    }
}

// Insert at beginning
void insert_begin() {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = head;
    head = newnode;
}

// Insert at end
void insert_end() {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        struct node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
    }
}

// Insert at position
void insert_pos() {
    int pos, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    struct node* newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if (pos == 1) {
        newnode->next = head;
        head = newnode;
        return;
    }

    struct node* temp = head;

    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

// Delete from beginning
void delete_begin() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node* temp = head;
    head = head->next;
    free(temp);
}

// Delete from end
void delete_end() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct node* temp = head;

    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}

// Delete from position
void delete_pos() {
    int pos, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (pos == 1) {
        struct node* temp = head;
        head = head->next;
        free(temp);
        return;
    }

    struct node* temp = head;

    for (i = 1; i < pos - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Invalid position\n");
        return;
    }

    struct node* del = temp->next;
    temp->next = del->next;
    free(del);
}

// Display list
void display() {
    struct node* temp = head;

    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main menu
int main() {
    int choice;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Create\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Position\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("7. Delete from Position\n");
        printf("8. Display\n");
        printf("9. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create();
                break;

            case 2:
                insert_begin();
                break;

            case 3:
                insert_end();
                break;

            case 4:
                insert_pos();
                break;

            case 5:
                delete_begin();
                break;

            case 6:
                delete_end();
                break;

            case 7:
                delete_pos();
                break;

            case 8:
                display();
                break;

            case 9:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
