#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(NULL), prev(NULL) {}
};

Node* head = NULL;
Node* tail = NULL; 

Node* head1 = NULL;
Node* tail1 = NULL;

Node* head2 = NULL;
Node* tail2 = NULL;

void addData(int val);
void splitList(int size);
void printList();

int main() {
	int size = 0;
    cout << "Splitting Linked List\n";
	cout << "Enter size of the linked list: ";
	cin >> size;
	
	int val, i = 0;
	while(i < size){
		cout << "Enter value for " << i+1 << "th node: ";
		cin >> val;
		addData(val);
		i++;
	}

	splitList(size);
	printList();
	
	return 0;	
	
}

void addData(int val) {
	
    Node* newNode = new Node(val);
    
    if(head == NULL){
    	head = tail = newNode;
	}
	else {
		newNode->next = head;
    	head->prev = newNode;
    	newNode->prev = NULL;
    	head = newNode;
	}
    if (tail == NULL) tail = newNode;
}

void splitList(int size){
	Node* curr = head;
	
	int val;
	int i = 0;
	int size_half = size / 2;
	
	if(size % 2 == 0){
		while (i < size_half){
			val = curr->data;
			
			Node* newNode = new Node(val);
			if(head1 == NULL){
    			head1 = tail1 = newNode;
			}
			else{
    			newNode->next = head1;
    			head1->prev = newNode;
    			newNode->prev = NULL;
    			head1 = newNode;
			}
    		if (tail1 == NULL) tail1 = newNode;
        		
			curr = curr->next;
			i++;
		}
		while (i < size){
			val = curr->data;
			
			Node* newNode = new Node(val);
			if(head2 == NULL){
    			head2 = tail2 = newNode;
			}
			else{
    			newNode->next = head2;
    			head2->prev = newNode;
    			newNode->prev = NULL;
    			head2 = newNode;
			}
    		if (tail2 == NULL) tail2 = newNode;
    		
			curr = curr->next;
			i++;
		}
	}
	else {
		while (i < ceil(size_half)){
			val = curr->data;
			
			Node* newNode = new Node(val);
			if(head1 == NULL){
    			head1 = tail1 = newNode;
			}
			else{
    			newNode->next = head1;
    			head1->prev = newNode;
    			newNode->prev = NULL;
    			head1 = newNode;
			}
    		if (tail1 == NULL) tail1 = newNode;
        		
			curr = curr->next;
			i++;
		}
		while (i < size){
			val = curr->data;
			
			Node* newNode = new Node(val);
			if(head2 == NULL){
    			head2 = tail2 = newNode;
			}
			else{
    			newNode->next = head2;
    			head2->prev = newNode;
    			newNode->prev = NULL;
    			head2 = newNode;
			}
    		if (tail2 == NULL) tail2 = newNode;
    		
			curr = curr->next;
			i++;
		}
	}
}

void printList() {
    cout << "List 1 ";
    Node* curr2 = tail2;
    while (curr2 != NULL) {
        cout << curr2->data << " ";
        curr2 = curr2->prev;
    }
    cout << "\n";
    
    cout << "List 2 ";
    Node* curr1 = tail1;
    while (curr1 != NULL) {
        cout << curr1->data << " ";
        curr1 = curr1->prev;
    }
    cout << "\n";
}
