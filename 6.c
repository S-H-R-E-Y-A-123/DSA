#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* next;
};

//Global head pointers for two linked lists
struct Node* head1 = NULL;
struct Node* head2 = NULL;
struct Node* head = NULL;

// Function to create a linked list 
void create(int size) {
    int data;
    struct Node *newNode, *temp;
    if (head != NULL) {
        printf("List already exists. Use insert to add elements.\n");
        return;
    }
    printf("Enter data for node 1: ");
    scanf("%d", &data);

    head = (struct Node*)malloc(sizeof(struct Node));//creating first node
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

// Function to insert at any position
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

// Function to concatenate two lists
void concatenateLists() {
    if (head1 == NULL) {
        head1 = head2;
    } else {
        struct Node* temp = head1;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = head2;
    }
    head2 = NULL;  // Clear the second list after concatenation
}

// Function to display the list
void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to reverse the linked list
void reverseList() {
    struct Node* prev = NULL;
    struct Node* temp = head;
    struct Node* next = NULL;

    while (temp != NULL) {
        next = temp->next;  // Store the next node
        temp->next = prev;  // Reverse the link
        prev = temp;        // Move prev one step forward
        temp = next;        // Move current one step forward
    }
    head = prev; // Update the head pointer to the new first node
    printf("Linked list reversed.\n");
}

//function to sort list (bubble sort)
void sortLinkedList() {
    struct Node* temp = head;
    struct Node* next = NULL;

    while (temp != NULL) {
        next = temp->next; // Initialize next for comparison
        while (next != NULL) {
            if (temp->data > next->data) {
                // Swap the data
                int swap = temp->data;
                temp->data = next->data;
                next->data = swap;
            }
            next = next->next; // Move to the next node
        }
        temp = temp->next; // Move to the next node for outer loop
    }
}

// Main menu function
int main() {
    int choice, size, data, position;

    while (1) {
        printf("\n\n--- Linked List Menu ---\n");
        printf("1. Create a Linked List\n");
        printf("2. Insert at a Position\n");
        printf("3. Reverse the Linked List\n");
        printf("4. Concatenate Two Linked Lists\n");
        printf("5. Display the Linked List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (head == NULL) {
                    printf("Enter the number of nodes to create: ");
                    scanf("%d", &size);
                    create(size);
                } else {
                    printf("A linked list already exists. Use the insert function to add elements.\n");
                }
                break;

            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                insert(data, position);
                break;

            case 3:
                reverseList();
                break;

            case 4:
                printf("Creating first linked list (head1)...\n");
                printf("Enter the number of nodes for the first list: ");
                scanf("%d", &size);
                head1 = NULL;  // Reset head1
                create(size);

                printf("Creating second linked list (head2)...\n");
                printf("Enter the number of nodes for the second list: ");
                scanf("%d", &size);
                head2 = NULL;  // Reset head2
                create(size);

                printf("Concatenating the two linked lists...\n");
                concatenateLists();
                printf("Linked lists concatenated successfully. The new list is:\n");
                displayList(head1);
                break;

            case 5:
                printf("Current Linked List: ");
                displayList(head);
                break;

            case 6:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
