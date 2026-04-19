#include <stdio.h>
#define MAX 100

int i;

// Function declarations
void display(int arr[], int n);
void insert(int arr[], int *n);
void delete(int arr[], int *n);
void update(int arr[], int n);

int main() {
    int arr[MAX], n, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\n--- MENU ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Update\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert(arr, &n);
                break;

            case 2:
                delete(arr, &n);
                break;

            case 3:
                update(arr, n);
                break;

            case 4:
                display(arr, n);
                break;

            case 5:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}

// Display function
void display(int arr[], int n) {
    if (n == 0) {
        printf("Array is empty\n");
        return;
    }

    printf("Array elements: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Insert function
void insert(int arr[], int *n) {
    int pos, value;

    if (*n >= MAX) {
        printf("Array is full\n");
        return;
    }

    printf("Enter position (0 to %d): ", *n);
    scanf("%d", &pos);

    if (pos < 0 || pos > *n) {
        printf("Invalid position\n");
        return;
    }

    printf("Enter value to insert: ");
    scanf("%d", &value);

    for (i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = value;
    (*n)++;

    printf("Element inserted successfully\n");
}

// Delete function
void delete(int arr[], int *n) {
    int pos;

    if (*n == 0) {
        printf("Array is empty\n");
        return;
    }

    printf("Enter position (0 to %d): ", *n - 1);
    scanf("%d", &pos);

    if (pos < 0 || pos >= *n) {
        printf("Invalid position\n");
        return;
    }

    for (i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*n)--;

    printf("Element deleted successfully\n");
}

// Update function
void update(int arr[], int n) {
    int pos, value;

    if (n == 0) {
        printf("Array is empty\n");
        return;
    }

    printf("Enter position (0 to %d): ", n - 1);
    scanf("%d", &pos);

    if (pos < 0 || pos >= n) {
        printf("Invalid position\n");
        return;
    }

    printf("Enter new value: ");
    scanf("%d", &value);

    arr[pos] = value;

    printf("Element updated successfully\n");
}
