#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a node structure
struct Friend {
    char name[100];          // Array to hold the name of the friend
    struct Friend* next;     // Pointer to the next node
};

// Function to create a new node with a friend's name
struct Friend* createNode(char* name) {
    struct Friend* newNode = (struct Friend*)malloc(sizeof(struct Friend));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    strcpy(newNode->name, name);  // Copy the name into the node
    newNode->next = NULL;          // Set the next pointer to NULL
    return newNode;
}

// Function to insert a new friend at the beginning of the list
void insertAtBeginning(struct Friend** head, char* name) {
    struct Friend* newNode = createNode(name);
    newNode->next = *head;  // Point the new node to the current head
    *head = newNode;        // Make the new node the head
}

// Function to insert a new friend at the end of the list
void insertAtEnd(struct Friend** head, char* name) {
    struct Friend* newNode = createNode(name);
    if (*head == NULL) {
        *head = newNode;   // If the list is empty, make the new node the head
        return;
    }
    struct Friend* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;  // Traverse to the last node
    }
    temp->next = newNode;  // Link the last node to the new node
}

// Function to delete a friend by name
void deleteByName(struct Friend** head, char* name) {
    struct Friend *temp = *head, *prev = NULL;

    // If the head node itself holds the name to be deleted
    if (temp != NULL && strcmp(temp->name, name) == 0) {
        *head = temp->next;  // Change head to the next node
        free(temp);          // Free the old head
        return;
    }

    // Search for the name to be deleted
    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    // If the name was not found
    if (temp == NULL) {
        printf("Friend with name %s not found!\n", name);
        return;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp);  // Free the node
}

// Function to display all friends
void displayList(struct Friend* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Friend* temp = head;
    while (temp != NULL) {
        printf("%s\n", temp->name);  // Print the friend's name
        temp = temp->next;           // Move to the next node
    }
}

// Function to search for a friend by name
void searchFriend(struct Friend* head, char* name) {
    struct Friend* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            printf("Found friend: %s\n", temp->name);
            return;
        }
        temp = temp->next;
    }
    printf("Friend with name %s not found.\n", name);
}

// Function to update a friend's name
void updateFriend(struct Friend* head, char* oldName, char* newName) {
    struct Friend* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->name, oldName) == 0) {
            strcpy(temp->name, newName);  // Update the name
            printf("Friend's name updated to: %s\n", temp->name);
            return;
        }
        temp = temp->next;
    }
    printf("Friend with name %s not found.\n", oldName);
}

// Main function to test the linked list operations
int main() {
    struct Friend* head = NULL;

    // Insert friends
    insertAtBeginning(&head, "Alice");
    insertAtEnd(&head, "Bob");
    insertAtEnd(&head, "Charlie");

    printf("Friends List:\n");
    displayList(head);  // Display the list of friends

    // Search for a friend
    searchFriend(head, "Bob");

    // Update a friend's name
    updateFriend(head, "Alice", "Alicia");

    printf("\nUpdated Friends List:\n");
    displayList(head);

    // Delete a friend
    deleteByName(&head, "Charlie");

    printf("\nFinal Friends List after deletion:\n");
    displayList(head);

    return 0;
}

