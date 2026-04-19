#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *L;
    struct node *R;
};

// Create new node
struct node* createNode(int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = data;
    newNode->L = NULL;
    newNode->R = NULL;

    return newNode;
}

// Insert into BST
struct node* createTree(struct node *root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->L = createTree(root->L, data);
    } 
    else if (data > root->data) {
        root->R = createTree(root->R, data);
    }

    return root;
}

// Inorder traversal
void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->L);
        printf("%d ", root->data);
        inorder(root->R);
    }
}

// Preorder traversal
void preorder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->L);
        preorder(root->R);
    }
}

// Postorder traversal
void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->L);
        postorder(root->R);
        printf("%d ", root->data);
    }
}

// Main function
int main() {
    struct node *root = NULL;
    int choice, data, n, i, m;

    do {
        printf("\n----- BINARY SEARCH TREE -----\n");
        printf("1. Create\n");
        printf("2. Display\n");
        printf("3. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter number of elements: ");
                scanf("%d", &n);

                for (i = 0; i < n; i++) {
                    printf("Enter element: ");
                    scanf("%d", &data);
                    root = createTree(root, data);
                }
                break;

            case 2:
                printf("\n1. Inorder\n2. Preorder\n3. Postorder\n");
                printf("Enter choice: ");
                scanf("%d", &m);

                switch (m) {
                    case 1:
                        inorder(root);
                        printf("\n");
                        break;

                    case 2:
                        preorder(root);
                        printf("\n");
                        break;

                    case 3:
                        postorder(root);
                        printf("\n");
                        break;

                    default:
                        printf("Invalid choice\n");
                }
                break;

            case 3:
                printf("Program Terminated\nThank you!\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 3);

    return 0;
}
