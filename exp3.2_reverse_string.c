#include <stdio.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push function
void push(char ch) {
    stack[++top] = ch;
}

// Pop function
char pop() {
    return stack[top--];
}

int main() {
    char arr[MAX];
    int i;

    printf("Enter a string: ");
    gets(arr); 

    // Push all characters into stack
    for (i = 0; arr[i] != '\0'; i++) {
        push(arr[i]);
    }

    // Pop characters back to reverse string
    for (i = 0; top != -1; i++) {
        arr[i] = pop();
    }

    printf("Reversed string: %s\n", arr);

    return 0;
}

