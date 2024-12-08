#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a node structure
struct Node {
    int data;            // Data to store the integer
    struct Node* next;   // Pointer to the next node
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert an integer into the odd-even linked list
void insert(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    
    // If the list is empty, initialize it with the new node
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // If the number is odd, insert at the beginning of the list
    if (data % 2 != 0) {
        newNode->next = *head;
        *head = newNode;
    }
    // If the number is even, insert at the end of the list
    else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;  // Traverse to the last node
        }
        temp->next = newNode;  // Add the new node at the end
    }
}

// Function to delete a node with a specific value
void deleteNode(struct Node** head, int data) {
    struct Node *temp = *head, *prev = NULL;

    // If the head node itself holds the data to be deleted
    if (temp != NULL && temp->data == data) {
        *head = temp->next;  // Change head
        free(temp);          // Free old head
        return;
    }

    // Search for the data to be deleted
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    // If the data was not found
    if (temp == NULL) {
        printf("Element %d not found in the list.\n", data);
        return;
    }

    // Unlink the node from the list
    prev->next = temp->next;
    free(temp);  // Free the memory
}

// Function to display the list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("List elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to search for an element in the list
void searchElement(struct Node* head, int data) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            printf("Element %d found in the list.\n", data);
            return;
        }
        temp = temp->next;
    }
    printf("Element %d not found in the list.\n", data);
}

// Function to update an element in the list
void updateElement(struct Node* head, int oldData, int newData) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == oldData) {
            temp->data = newData;
            printf("Element updated from %d to %d.\n", oldData, newData);
            return;
        }
        temp = temp->next;
    }
    printf("Element %d not found in the list.\n", oldData);
}

// Main function to test the odd-even linked list
int main() {
    struct Node* head = NULL;

    // Insert some elements into the list
    insert(&head, 10);  // Even
    insert(&head, 3);   // Odd
    insert(&head, 7);   // Odd
    insert(&head, 2);   // Even
    insert(&head, 5);   // Odd
    insert(&head, 8);   // Even

    // Display the list
    printf("Initial list:\n");
    displayList(head);

    // Search for an element
    searchElement(head, 7);
    searchElement(head, 15);

    // Update an element
    updateElement(head, 7, 17);

    // Display the list after updating
    printf("\nList after updating an element:\n");
    displayList(head);

    // Delete an element
    deleteNode(&head, 2);

    // Display the list after deletion
    printf("\nList after deleting an element:\n");
    displayList(head);

    return 0;
}

