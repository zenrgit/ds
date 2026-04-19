#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push function
void push(int x) {
    stack[++top] = x;
}

// Pop function
int pop() {
    return stack[top--];
}

int main() {
    int arr[MAX], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        push(arr[i]);
    }

    // Reverse using stack
    for (i = 0; i < n; i++) {
        arr[i] = pop();
    }

    printf("Reversed array is:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
