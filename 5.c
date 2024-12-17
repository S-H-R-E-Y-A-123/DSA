#include <stdio.h>
#include <stdlib.h>

// Definition of the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Global head pointer
struct Node* head = NULL;

// Function prototypes
void create(int data);
void insert(int data, int position);
void deleteNode(int data);
void display();

int main() {
    int choice, data, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create list\n");
        printf("2. Insert an element\n");
        printf("3. Delete an element\n");
        printf("4. Display the list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to create the list: ");
                scanf("%d", &data);
                create(data);
                break;

            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at (0 for beginning): ");
                scanf("%d", &position);
                insert(data, position);
                break;

            case 3:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNode(data);
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

// Function to create the linked list with the first node
void create(int size) {
    if (head != NULL) {
        printf("List already exists. Use insert to add elements.\n");
        return;
    }

    int data;
    struct Node *newNode, *temp;

    printf("Enter data for node 1: ");
    scanf("%d", &data);

    // Create the first node
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = data;
    head->next = NULL;

    temp = head; // Temp pointer to keep track of the last node

    // Loop to create the remaining nodes
    for (int i = 2; i <= size; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;

        temp->next = newNode; // Link the new node to the previous node
        temp = newNode;       // Move the temp pointer to the last node
    }

    printf("Linked list created with %d nodes.\n", size);
}  

// Function to insert a new node at a specific position
void insert(int data, int position) {
    int i;
    struct Node* temp, *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // Inserting at the head
    if (position == 1) {
        newNode->next = head;
        head = newNode;
        printf("DATA INSERTED SUCCESSFULLY AT POSITION %d (HEAD)\n", position);
        return;
    }

    // Traverse to the n-1 position
    for (i = 2; i <= position - 1; i++) {
        if (temp == NULL) {
            break; // Stop if we reach the end of the list
        }
        temp = temp->next;
    }if (temp != NULL) {
        newNode->next = temp->next;
        temp->next = newNode;
        printf("DATA INSERTED SUCCESSFULLY AT POSITION %d\n", position);

    } else {
        temp = head;

        // Traverse to the last node
        while (temp != NULL && temp->next != NULL) {
            temp = temp->next;
        }
        printf("POSITION OUT OF BOUNDS. DATA INSERTED AT THE END.\n");
    }
}

// Function to delete a node by value
void deleteNode(int data) {
    struct Node* temp = head;
    struct Node* prev = NULL;

    // If the head node itself holds the data to be deleted
    if (temp != NULL && temp->data == data) {
        head = temp->next;
        free(temp);
        printf("Deleted %d from the list.\n", data);
        return;
    }
    // Search for the data to be deleted, keep track of the previous node
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }
    // If data was not present in the list
    if (temp == NULL) {
        printf("Element %d not found in the list.\n", data);
        return;
    }
    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp);
    printf("Deleted %d from the list.\n", data);
}

// Function to display the linked list
void display() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("Linked list elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to display elements at even positions
void displayEvenPositionElements() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    int position = 1; // Start from the first node
    
    printf("Elements at even positions: ");
    while (temp != NULL) {
        if (position % 2 == 0) {  // Check if position is even
            printf("%d -> ", temp->data);
        }
        temp = temp->next;
        position++;
    }
    printf("NULL\n");
}
