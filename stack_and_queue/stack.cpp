#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
#define N 5

int top = -1;
int stack[N];
bool isFull();
bool isEmpty();
void push(int a);
void pop();
int peek();
void printStack();

int main() {
    cout << "Stack Implementation\n";
    cout << "0. Exit\n"
           "1: Push\n"
           "2: Pop\n"
           "3: Is the stack empty?\n"
           "4: Is the stack full?\n"
           "5: Want to peek?\n"
           "6: Print the stack\n";
           
    while(true){
        int option, ans;
        string full, empty;
        cout << "Enter choice: ";
        cin >> option;
    
        switch(option){
            case 0:
                cout << "Exiting…\n";
                exit(EXIT_SUCCESS);
                break;
            
            case 1:
                cout << "Enter value: ";
                int a;
                cin >> a;
                push(a);
                cout << "Success\n";
                break;
            
            case 2:
                pop();
                cout << "Success\n";
                break;
            
            case 3:
                empty = (isEmpty()) ? "Yes" : "No";
                cout << empty << '\n';
                break;
            
            case 4:
                full = (isFull()) ? "Yes" : "No";
                cout << full << '\n';
                break;
            
            case 5:
                ans = peek();
                cout << "Top element is " << ans <<'\n';
                break;
            
            case 6:
                printStack();
                cout << '\n';
                break;
                
            default:
                cout << "Invalid\n";
                break;
        }
    }
}

bool isEmpty(){
    if (top == -1) return true;
    else return false;
}

bool isFull(){
    if (top == N - 1) return true;
    else return false;
}

void push(int a){
    if(top == N - 1){
        cout << "Overflow\n";
    }
    else{
        top++;
        stack[top] = a;
    }
}

void pop(){
    if(top < 0){
        cout << "Underflow\n";
    }
    else {
        int value = stack[top--];
        cout << value << '\n';
    }
}

int peek(){
    if (isEmpty()){
        cout << "EMPTY STACK\n";
        return -1;
    }
    return stack[top];
}

void printStack(){
    for(int i = 0;i <= top; i++){
        cout << stack[i] << " ";
    }
}