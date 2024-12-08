#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    char data;
    Node* next;
    
    
    Node(char val) : data(val), next(nullptr) {}
};

// LinkedList class to encapsulate the linked list operations
class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList() : head(nullptr) {}

    // Function to get the length of the linked list
    int getLength() {
        int length = 0;
        Node* current = head;
        while (current != nullptr) {
            length++;
            current = current->next;
        }
        return length;
    }

    // Function to add a node at the beginning
    void addAtBeg(char x) {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
    }

    // Function to append a node at the end
    void append(char x) {
        Node* newNode = new Node(x);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    // Function to add a node at a specific position
    void addAtPOS(char x, int pos) {
        if (pos < 1 || pos > getLength() + 1) {
            cout << "Invalid position!" << endl;
            return;
        }
        Node* newNode = new Node(x);
        if (pos == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* current = head;
        for (int i = 1; i < pos - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    // Function to display the linked list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Function to display address, value, and next node address
    void displayMORE() {
        Node* current = head;
        while (current != nullptr) {
            cout << "Address: " << current << ", Value: " << current->data
                 << ", Next Address: " << current->next << endl;
            current = current->next;
        }
    }

    // Function to remove the first node
    void removeFirst() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Function to remove the last node
    void removeLast() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* current = head;
        while (current->next && current->next->next != nullptr) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }

    // Function to remove a node at a specific position
    void removePOS(int pos) {
        if (pos < 1 || pos > getLength()) {
            cout << "Invalid position!" << endl;
            return;
        }
        if (pos == 1) {
            removeFirst();
            return;
        }
        Node* current = head;
        for (int i = 1; i < pos - 1; i++) {
            current = current->next;
        }
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    // Destructor to clean up the memory
    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;

    // Operations
    list.addAtBeg('A');
    list.append('B');
    list.append('C');
    list.addAtPOS('D', 2);  // Insert D at position 2
    list.display();          // Output: A D B C
    
    cout << "Length of list: " << list.getLength() << endl; // Output: 4

    list.displayMORE(); // Display address, value, and next address
    
    list.removeFirst(); // Remove first element
    list.display();      // Output: D B C
    
    list.removeLast();  // Remove last element
    list.display();      // Output: D B
    
    list.removePOS(2);   // Remove element at position 2
    list.display();      // Output: D

    return 0;
}

