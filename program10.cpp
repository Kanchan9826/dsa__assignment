#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// Define a structure for a contact entry
struct Contact {
    string name;          // Name of the friend
    string mobileNumber;  // Mobile number of the friend
    Contact* next;        // Pointer to the next contact in the list
};

// Function to create a new contact node
Contact* createNode(string name, string mobileNumber) {
    Contact* newNode = new Contact();
    if (!newNode) {
        cout << "Memory allocation failed!\n";
        return nullptr;
    }
    newNode->name = name;
    newNode->mobileNumber = mobileNumber;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert a new contact at the end of the list
void insertContact(Contact*& head, string name, string mobileNumber) {
    Contact* newNode = createNode(name, mobileNumber);
    
    // If the list is empty, make the new node the head
    if (!head) {
        head = newNode;
        return;
    }

    // Traverse to the end of the list and insert the new node
    Contact* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a contact by name
void deleteContactByName(Contact*& head, string name) {
    if (!head) {
        cout << "The list is empty.\n";
        return;
    }

    Contact* temp = head;
    Contact* prev = nullptr;

    // If the head node itself contains the name to be deleted
    if (temp != nullptr && temp->name == name) {
        head = temp->next;  // Move the head to the next node
        delete temp;        // Free the memory
        return;
    }

    // Search for the contact by name
    while (temp != nullptr && temp->name != name) {
        prev = temp;
        temp = temp->next;
    }

    // If the name is not found
    if (temp == nullptr) {
        cout << "Contact with name " << name << " not found.\n";
        return;
    }

    // Unlink the contact from the list
    prev->next = temp->next;
    delete temp;  // Free the memory
}

// Function to delete a contact by mobile number
void deleteContactByMobile(Contact*& head, string mobileNumber) {
    if (!head) {
        cout << "The list is empty.\n";
        return;
    }

    Contact* temp = head;
    Contact* prev = nullptr;

    // If the head node itself contains the mobile number to be deleted
    if (temp != nullptr && temp->mobileNumber == mobileNumber) {
        head = temp->next;  // Move the head to the next node
        delete temp;        // Free the memory
        return;
    }

    // Search for the contact by mobile number
    while (temp != nullptr && temp->mobileNumber != mobileNumber) {
        prev = temp;
        temp = temp->next;
    }

    // If the mobile number is not found
    if (temp == nullptr) {
        cout << "Contact with mobile number " << mobileNumber << " not found.\n";
        return;
    }

    // Unlink the contact from the list
    prev->next = temp->next;
    delete temp;  // Free the memory
}

// Function to search for a contact by name
void searchContactByName(Contact* head, string name) {
    Contact* temp = head;
    while (temp != nullptr) {
        if (temp->name == name) {
            cout << "Found contact: " << temp->name << ", " << temp->mobileNumber << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Contact with name " << name << " not found.\n";
}

// Function to search for a contact by mobile number
void searchContactByMobile(Contact* head, string mobileNumber) {
    Contact* temp = head;
    while (temp != nullptr) {
        if (temp->mobileNumber == mobileNumber) {
            cout << "Found contact: " << temp->name << ", " << temp->mobileNumber << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Contact with mobile number " << mobileNumber << " not found.\n";
}

// Function to update a contact's name or mobile number
void updateContact(Contact* head, string oldName, string newName, string newMobileNumber) {
    Contact* temp = head;
    while (temp != nullptr) {
        if (temp->name == oldName) {
            temp->name = newName;
            temp->mobileNumber = newMobileNumber;
            cout << "Updated contact: " << temp->name << ", " << temp->mobileNumber << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Contact with name " << oldName << " not found.\n";
}

// Function to display all contacts in the list
void displayContacts(Contact* head) {
    if (!head) {
        cout << "The list is empty.\n";
        return;
    }

    Contact* temp = head;
    cout << "Contact List:\n";
    while (temp != nullptr) {
        cout << "Name: " << temp->name << ", Mobile: " << temp->mobileNumber << endl;
        temp = temp->next;
    }
}

// Function to count the total number of contacts
int countContacts(Contact* head) {
    int count = 0;
    Contact* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Main function to test the contact list
int main() {
    Contact* head = nullptr;

    // Insert some contacts
    insertContact(head, "Alice", "1234567890");
    insertContact(head, "Bob", "2345678901");
    insertContact(head, "Charlie", "3456789012");
    insertContact(head, "David", "4567890123");

    // Display all contacts
    cout << "Initial contact list:\n";
    displayContacts(head);

    // Search for a contact by name
    searchContactByName(head, "Bob");

    // Search for a contact by mobile number
    searchContactByMobile(head, "3456789012");

    // Update a contact's details
    updateContact(head, "Alice", "Alicia", "9876543210");

    // Display the updated list
    cout << "\nUpdated contact list:\n";
    displayContacts(head);

    // Delete a contact by name
    deleteContactByName(head, "Bob");

    // Delete a contact by mobile number
    deleteContactByMobile(head, "4567890123");

    // Display the list after deletions
    cout << "\nContact list after deletions:\n";
    displayContacts(head);

    // Count the number of contacts
    int totalContacts = countContacts(head);
    cout << "\nTotal contacts in the list: " << totalContacts << endl;

    return 0;
}

