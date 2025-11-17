#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int data) : data(data), next(NULL), prev(NULL) {}
};

Node* getData() {
    Node* head = NULL;
    Node* tail = NULL;
    int val;
    while (true) {
        cout << "Enter val: ";
        cin >> val;

        if (val == -1) break;

        Node* newnode = new Node(val);
        if (head == NULL) head = tail = newnode;
        else {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }
    return head;
}

Node* sortList(Node* head) {
    int size = 0;
    Node* cur = head;
    while (cur) { size++; cur = cur->next; }

    for (int step = 0; step < size - 1; step++) {
        Node* currPrev = head;
        Node* currNext = currPrev->next;

        for (int j = 0; j < size - step - 1; j++) {
            if (currPrev->data > currNext->data) {
                int temp = currPrev->data;
                currPrev->data = currNext->data;
                currNext->data = temp;
            }
            currPrev = currNext;
            currNext = currNext->next;
        }
    }
    return head;
}

void printList(Node* head) {
    Node* cur = head;
    while (cur != NULL) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << "\n";
}

Node* mergeLists(Node* head1, Node* head2) {
    Node* head3 = NULL;
    Node* tail3 = NULL;
    Node* cur1 = head1;
    Node* cur2 = head2;

    while (cur1 != NULL && cur2 != NULL) {
        int val;
        if (cur1->data <= cur2->data) {
            val = cur1->data;
            cur1 = cur1->next;
        } else {
            val = cur2->data;
            cur2 = cur2->next;
        }
        Node* newnode = new Node(val);
        if (head3 == NULL) head3 = tail3 = newnode;
        else {
            tail3->next = newnode;
            newnode->prev = tail3;
            tail3 = newnode;
        }
    }
    while (cur1 != NULL) {
        Node* newnode = new Node(cur1->data);
        tail3->next = newnode;
        newnode->prev = tail3;
        tail3 = newnode;
        cur1 = cur1->next;
    }
    while (cur2 != NULL) {
        Node* newnode = new Node(cur2->data);
        tail3->next = newnode;
        newnode->prev = tail3;
        tail3 = newnode;
        cur2 = cur2->next;
    }
    return head3;
}

int main() {
    cout << "Enter data for 1st list\n";
    Node* firstListHead = getData();

    cout << "Enter data for 2nd list\n";
    Node* secondListHead = getData();

    firstListHead = sortList(firstListHead);
    secondListHead = sortList(secondListHead);

    Node* merged = mergeLists(firstListHead, secondListHead);
    cout << "Merged Sorted List: ";
    printList(merged);

    return 0;
}