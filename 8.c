#include <stdio.h>
#include <stdlib.h>

// Definition of the Node structure
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Global head pointer
struct Node* head = NULL;

// Function prototypes
void create(int n);
void insert(int data, int position);
void displayStraight();
void displayReverse();

int main() {
    int choice, data, position, n;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create list\n");
        printf("2. Insert an element\n");
        printf("3. Display list in straight order\n");
        printf("4. Display list in reverse order\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (head != NULL) {
                    printf("List already exists. Use insert to add elements.\n");
                    break;
                }
                printf("Enter the number of elements to create the list: ");
                scanf("%d", &n);
                create(n);
                break;

            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at (0 for beginning): ");
                scanf("%d", &position);
                insert(data, position);
                break;

            case 3:
                displayStraight();
                break;

            case 4:
                displayReverse();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

// Function to create the doubly linked list with 'n' nodes
void create(int n) {
    struct Node *newNode, *temp;
    int data, i;

    if (n <= 0) {
        printf("Number of elements must be greater than zero.\n");
        return;
    }

    for (i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (head == NULL) {  // If creating the first node
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }
    printf("List created with %d nodes.\n", n);
}

// Function to insert a new node at a specific position
void insert(int data, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (position == 0) {
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        printf("Inserted %d at the beginning.\n", data);
        return;
    }

    struct Node* temp = head;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds. Inserting at the end.\n");
    } else {
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        printf("Inserted %d at position %d.\n", data, position);
    }
}

// Function to display the list in straight order
void displayStraight() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("Doubly linked list in straight order: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to display the list in reverse order
void displayReverse() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }

    // Move to the end of the list
    while (temp->next != NULL) {
        temp = temp->next;
    }
    printf("Doubly linked list in reverse order: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}