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
    curr->next = newNode; // current node will now point to the newnode. So curr's old linkage with next node is broken and only newnode is now pointing to the next node

    if (curr == tail) // If the position was end, we also make the newnode as tail
        tail = newNode;
}

void deleteFromBeginning() {
    if (head == NULL) { // if list is empty
        cout << "List is empty\n";
        return;
    }
    // while deleting, we always make a temporary node, BUT IT'S ONLY A POINTER
    Node* temp = head; // temporary node pointer, pointing to head- this head will be deleted
    head = head->next; // we increment the head by one, so the next node is now head
    delete temp; // delete this old head

    if (head == NULL) // If list becomes empty after deleting
        tail = NULL;
}

void deleteFromEnd() {
    if (head == NULL) { // if list is empty
        cout << "List is empty\n";
        return;
    }

    if (head->next == NULL) { // if there's only one node
        delete head; // delete that one node, i.e head in this case
        head = tail = NULL; // reset head and tail pointers to NULL
        return;
    }

    // while traversing, we always make a current node, BUT ITS ONLY A POINTER
    Node* curr = head; // current node pointer, pointing to head- we will start traversing from head. 
    while (curr->next != tail) { // traverse till one node previous to tail.
        curr = curr->next; // current node keeps on moving forward
    }
    delete tail; // current node is pointing to one node previous to tail. This current node is our new tail so we delete old tail
    curr->next = NULL; // current node's next address will be NULL
    tail = curr; // our new tail is current node (we rename curr to tail)
}

void deleteFromPosition(int pos) {
    if (head == NULL) { // If list is empty
        cout << "List is empty\n";
        return;
    }
    if (pos == 0) { // If position is 0 we call deleteFromBeginning()
        deleteFromBeginning();
        return;
    }
    
    Node* curr = head; // we will traverse to that position so we make current node pointer
    int index = 0;
    while (curr->next && index < pos - 1) { // We're going to delete curr->next, So we must ensure that curr->next actually exists— we can't delete something that's not there!
        curr = curr->next;
        index++;
    }
    if (curr->next == NULL) {
        cout << "Position out of bounds\n";
        return;
    }
    Node* delNode = curr->next; // delNode pointer created. curr->next is basically the node we wish to delete i.e delNode
    curr->next = delNode->next; // we change curr's address to the address of delNode's next. this way, delNode's prev node (curr) now skips delNode and points to next node of delNode

    if (delNode == tail) // if delNode turns out to be tail, the current node becomes tail
        tail = curr;

    delete delNode; // delete desired node i.e delNode
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





