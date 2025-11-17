#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int data) : data(data), next(NULL), prev(NULL) {}
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
    cout << "Doubly Linked List Implementation\n";
    cout << "0. Exit\n"
           "1: Add at Beginning\n"
           "2: Add at End\n"
           "3: Add at Arbitrary Position\n"
           "4: Delete from Beginning\n"
           "5: Delete from End\n"
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
                cout << "Enter position (0 based): ";
                cin >> pos;
                cout << "Enter value: ";
                cin >> value;
                addAtPosition(value, pos);
                cout << "Success\n";
                break;

            case 4:
                deleteFromBeginning();
                cout << "Success\n";
                break;

            case 5:
                deleteFromEnd();
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
   Node* newnode = new Node(val);

   if(head == NULL){ // empty list so point first node to both head and tail
        head = tail = newnode;
    } 

    else { 
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}

void addAtEnd(int val) {
    Node* newnode = new Node(val);

    if(head == NULL){  // empty list so point first node to both head and tail
        head = tail = newnode;
    } 

    else {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}

void addAtPosition(int val, int pos) {
    if(head == NULL){ 
        cout << "List is empty";
        return;
    }

    if(pos < 0) {
        cout << "Invalid position.\n";
        return;
    }

    if(pos == 0){
        addAtBeginning(val);
        return;
    }

    int index = 0;
    Node* curr = head;
    while(index < pos - 1 && curr != NULL){
        curr = curr->next;
        index++;
    }

    if(curr == NULL){
        cout <<" Out of bounds";
        return;
    }

    Node* newnode = new Node(val);

    if(curr->next == NULL){
        tail->next = newnode;
        newnode->next = NULL;
        newnode->prev = tail;
        tail = newnode;
    }
    
    else {
        newnode->next = curr->next;
        newnode->prev = curr;
        curr->next->prev = newnode;
        curr->next = newnode;
    }
}

void deleteFromBeginning() {
    if(head == NULL){ 
        cout << "List is empty";
        return;
    }

    Node* temp = head;

    if(temp->next == NULL){ // only one node in list
        head = tail = NULL; // reset head and tail
        delete temp; // delete that singlde node
    }
    else {
        head = head->next;
        head->prev = NULL;
        delete temp;
    }
}

void deleteFromEnd() {
    if(head == NULL){ 
        cout << "List is empty";
        return;
    }

    Node* temp = tail;
    if(temp == head){
        head = tail = NULL;
        delete temp;
        return;
    }

    tail = tail->prev;
    tail->next = NULL;
    delete temp;
}

void deleteFromPosition(int pos) {
    if(head == NULL){ 
        cout << "List is empty";
        return;
    }

    if(pos < 0) {
        cout << "Invalid position.\n";
        return;
    }

    if(pos == 0){
        deleteFromBeginning();
        return;
    }

    int index = 0;
    Node* curr = head;

    while(curr != NULL && index < pos){
        curr = curr->next;
        index++;
    }

    if(curr == NULL){
        cout << "Index Out of bounds";
        return;
    }

    if(curr->next == NULL){
        deleteFromEnd();
        return;
    }
    // we reach the current node we wish to delete
    curr->prev->next = curr->next; // we store the add of current's next node into current node's prev node (front linkin)
    curr->next->prev = curr->prev; // we store the add of current's prev into current's next (back linking) 
    delete curr;
}

void printList() {
    if(head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* curr = head;

    while(curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << "\n";
}