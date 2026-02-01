#include <stdio.h>
#include <stdlib.h>

// 1. Define the Node Structure
struct Node {
    int data;
    struct Node* next;
};

// Function Prototypes
struct Node* createNode(int data);
void insertAtBeginning(struct Node** head, int data);
void insertAtEnd(struct Node** head, int data);
void deleteNode(struct Node** head, int key);
void traverseList(struct Node* head);

int main() {
    struct Node* head = NULL; // Initialize an empty list
    int choice, value, key;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete a Node\n");
        printf("4. Traverse (Display) List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &key);
                deleteNode(&head, key);
                break;
            case 4:
                traverseList(head);
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Helper function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 2. Insert at Beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head; // Point new node to current head
    *head = newNode;       // Update head to be the new node
    printf("Inserted %d at the beginning.\n", data);
}

// 3. Insert at End
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    
    // If list is empty, make new node the head
    if (*head == NULL) {
        *head = newNode;
        printf("Inserted %d at the end (first node).\n", data);
        return;
    }

    // Traverse to the last node
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode; // Link last node to new node
    printf("Inserted %d at the end.\n", data);
}

// 4. Delete a Node by Value
void deleteNode(struct Node** head, int key) {
    struct Node *temp = *head, *prev = NULL;

    // Case 1: If the head node itself holds the key
    if (temp != NULL && temp->data == key) {
        *head = temp->next; // Change head
        free(temp);         // Free old head
        printf("Deleted %d from the list.\n", key);
        return;
    }

    // Case 2: Search for the key to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) {
        printf("Element %d not found in the list.\n", key);
        return;
    }

    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp);
    printf("Deleted %d from the list.\n", key);
}

// 5. Traverse (Display) the List
void traverseList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}