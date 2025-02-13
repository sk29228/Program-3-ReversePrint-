#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;

    // Private recursive function to print the list in reverse
    void reversePrintHelper(Node* node) const {
        if (node == nullptr) {
            return;
        }
        reversePrintHelper(node->next); // Recursive call
        cout << node->data << " <- ";  // Print in reverse order
    }

public:
    SinglyLinkedList() : head(nullptr) {}

    // Insert a new node at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Display the list in normal order
    void displayList() const {
        Node* temp = head;
        cout << "Head -> ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

    // Public function to call the private recursive function
    void reversePrint() const {
        cout << "Reverse print the list:" << endl;
        cout << "nullptr <- ";
        reversePrintHelper(head);
        cout << "Head" << endl;
    }
};

// Test program
int main() {
    SinglyLinkedList list;

    // Adding at least 10 elements
    list.insertAtEnd(5);
    list.insertAtEnd(10);
    list.insertAtEnd(15);
    list.insertAtEnd(20);
    list.insertAtEnd(25);
    list.insertAtEnd(30);
    list.insertAtEnd(35);
    list.insertAtEnd(40);
    list.insertAtEnd(45);
    list.insertAtEnd(50);

    // Display the list in normal order
    cout << "Print the list:" << endl;
    list.displayList();

    // Display the list in reverse order
    list.reversePrint();

    return 0;
}
