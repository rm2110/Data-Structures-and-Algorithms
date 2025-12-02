#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) : data(data), next(NULL) {}
};

Node* head = NULL;
Node* tail = NULL; 

void addAtBeginning(int val);
void addAtEnd(int val);
void addAtPosition(int val, int pos);
void deleteFromBeginning();
void deleteFromEnd();
void deleteFromPosition(int pos);
void printList();

int main() {
    cout << "Linked List Implementation\n";
    cout << "0. Exit\n"
           "1: Add at Beginning\n"
           "2: Add at End\n"
           "3: Delete from Beginning\n"
           "4: Delete from End\n"
           "5: Add at Arbitrary Position\n"
           "6: Delete from Arbitrary Position\n"
           "7: Print Linked List\n";

    while(true) {
        int option, value, pos;
        cout << "Enter choice: ";
        cin >> option;

        switch(option) {
            case 0:
                cout << "Exiting...\n";
                exit(EXIT_SUCCESS);
                return 0;

            case 1:
                cout << "Enter value: ";
                cin >> value;
                addAtBeginning(value);
                cout << "Success\n";
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                addAtEnd(value);
                cout << "Success\n";
                break;

            case 3:
                deleteFromBeginning();
                cout << "Success\n";
                break;

            case 4:
                deleteFromEnd();
                cout << "Success\n";
                break;

            case 5:
                cout << "Enter position (0 based): ";
                cin >> pos;
                cout << "Enter value: ";
                cin >> value;
                addAtPosition(value, pos);
                cout << "Success\n";
                break;

            case 6:
                cout << "Enter position (0 based): ";
                cin >> pos;
                deleteFromPosition(pos);
                cout << "Success\n";
                break;

            case 7:
                printList();
                break;

            default:
                cout << "Invalid\n";
        }
    }
}

void addAtBeginning(int val) {
    Node* newNode = new Node(val); 
    newNode->next = head; 
    head = newNode; 

    if (tail == NULL) 
        tail = newNode; 
}

void addAtEnd(int val) {
    Node* newNode = new Node(val); 
    if (head == NULL) {  
        head = tail = newNode; 
        return;
    }

    tail->next = newNode; 
    tail = newNode; 
}

void addAtPosition(int val, int pos) {
    if (pos == 0) { 
        addAtBeginning(val);
        return;
    }

    Node* curr = head; 
    int index = 0; 
    while (curr != NULL && index < pos - 1) { 
        curr = curr->next; 
        index++; 
    }
    if (curr == NULL) { 
        cout << "Position out of bounds\n";
        return;
    }

    Node* newNode = new Node(val); 
    newNode->next = curr->next;
    curr->next = newNode; 

    if (curr == tail) 
        tail = newNode;
}

void deleteFromBeginning() {
    if (head == NULL) { 
        cout << "List is empty\n";
        return;
    }
    
    Node* temp = head; 
    head = head->next; 
    delete temp; 

    if (head == NULL) 
        tail = NULL;
}

void deleteFromEnd() {
    if (head == NULL) { 
        cout << "List is empty\n";
        return;
    }

    if (head->next == NULL) {
        delete head; 
        head = tail = NULL; 
        return;
    }

    Node* curr = head; 
    while (curr->next != tail) { 
        curr = curr->next;
    }
    delete tail; 
    curr->next = NULL; 
    tail = curr; 
}

void deleteFromPosition(int pos) {
    if (head == NULL) { 
        cout << "List is empty\n";
        return;
    }
    if (pos == 0) { 
        deleteFromBeginning();
        return;
    }
    
    Node* curr = head;
    int index = 0;
    while (curr->next && index < pos - 1) {
        curr = curr->next;
        index++;
    }
    if (curr->next == NULL) {
        cout << "Position out of bounds\n";
        return;
    }
    Node* delNode = curr->next;
    curr->next = delNode->next; 

    if (delNode == tail) 
        tail = curr;

    delete delNode; 
}

void printList() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    Node* curr = head;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << "\n";
}
