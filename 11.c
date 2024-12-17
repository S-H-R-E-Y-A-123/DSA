#include <stdio.h>
#include <stdlib.h>

// Definition of the Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function prototypes
struct Node* createNode(int data);
struct Node* insert(struct Node* root, int data);
void inorderTraversal(struct Node* root);
struct Node* findMin(struct Node* root);
struct Node* findMax(struct Node* root);

int main() {
    struct Node* root = NULL;
    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert an element in the BST\n");
        printf("2. Inorder traversal\n");
        printf("3. Find smallest element\n");
        printf("4. Find largest element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;

            case 2:
                printf("Inorder traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;

            case 3: {
                struct Node* minNode = findMin(root);
                if (minNode != NULL) {
                    printf("Smallest element is: %d\n", minNode->data);
                } else {
                    printf("The tree is empty.\n");
                }
                break;
            }

            case 4: {
                struct Node* maxNode = findMax(root);
                if (maxNode != NULL) {
                    printf("Largest element is: %d\n", maxNode->data);
                } else {
                    printf("The tree is empty.\n");
                }
                break;
            }

            case 5:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    } else {
        printf("Duplicate data not allowed in BST.\n");
    }
    return root;
}

// Function for inorder traversal (Left, Root, Right)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to find the node with the minimum value in the BST
struct Node* findMin(struct Node* root) {
    if (root == NULL) {
        return NULL;
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to find the node with the maximum value in the BST
struct Node* findMax(struct Node* root) {
    if (root == NULL) {
        return NULL;
    }
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}
