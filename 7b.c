#include <stdio.h>
#include <stdlib.h>

// Define node structure for circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Global head pointer for circular linked list
struct Node* head = NULL;

// Function to create a circular linked list with the first node
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
    head->next = head; // The next of head points to itself for circular structure

    temp = head; // Temp pointer to keep track of the last node

    // Loop to create the remaining nodes
    for (int i = 2; i <= size; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = head; // Point the new node to head (circular link)

        temp->next = newNode; // Link the new node to the previous node
        temp = newNode;       // Move the temp pointer to the last node
    }

    printf("Circular linked list created with %d nodes.\n", size);
}  

// Function to insert a new node at a specific position
void insert(int data, int position) {
    int i;
    struct Node* temp, *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // Inserting at the head (position 1)
    if (position == 1) {
        if (head == NULL) {
            head = newNode;
            newNode->next = head; // Circular link for a single node
        } else {
            newNode->next = head;
            struct Node* temp = head;
            // Traverse to last node to complete the circular link
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode; // Point last node to the new node
            head = newNode;       // Update head to new node
        }
        printf("DATA INSERTED SUCCESSFULLY AT POSITION %d (HEAD)\n", position);
        return;
    }

    // Traverse to the n-1 position
    temp = head;
    for (i = 2; i < position && temp->next != head; i++) {
        temp = temp->next;
    }

    if (i == position) {
        newNode->next = temp->next;
        temp->next = newNode;
        printf("DATA INSERTED SUCCESSFULLY AT POSITION %d\n", position);
    } else {
        printf("POSITION OUT OF BOUNDS. DATA INSERTED AT THE END.\n");
        newNode->next = head;
        temp->next = newNode;
    }
}

// Function to delete a node by value
void deleteNode(int data) {
    struct Node* temp = head;
    struct Node* prev = NULL;

    // If the head node itself holds the data to be deleted
    if (temp != NULL && temp->data == data) {
        if (temp->next == head) {  // Only one node in the list
            free(temp);
            head = NULL;
        } else {
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = head->next;
            free(head);
            head = temp->next;
        }
        printf("Deleted %d from the list.\n", data);
        return;
    }

    // Search for the data to be deleted, keep track of the previous node
    prev = NULL;
    temp = head;
    while (temp->next != head && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    // If data was not present in the list
    if (temp == head && temp->data != data) {
        printf("Element %d not found in the list.\n", data);
        return;
    }

    // Unlink the node from the circular linked list
    prev->next = temp->next;
    free(temp);
    printf("Deleted %d from the list.\n", data);
}

// Function to display the circular linked list
void display() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("Circular linked list elements: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

int main() {
    int choice, data, position, size;

    // Create a circular linked list with 3 nodes
    printf("Enter the number of nodes to create: ");
    scanf("%d", &size);
    create(size);
    display();

    // Insert a node with value 25 at position 2
    printf("Enter the data to insert: ");
    scanf("%d", &data);
    printf("Enter the position to insert at: ");
    scanf("%d", &position);
    insert(data, position);
    display();

    // Delete a node with value 20
    printf("Enter the value to delete: ");
    scanf("%d", &data);
    deleteNode(data);
    display();

    return 0;
}