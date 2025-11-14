#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int front = -1, rear = -1;
int capacity = 0;
int *queueArr = NULL;

bool isFull();
bool isEmpty();
void enqueue(int a);
void dequeue();
int peek();
void printQueue();

int main() {
    cout << "Queue Implementation\n";
    cout << "Enter desired queue size: ";
    cin >> capacity;
    if (capacity <= 0) {
        cout << "Invalid size\n";
        return 0;
    }
    queueArr = new int[capacity];

    cout << "0: Exit\n"
         << "1: Enqueue\n"
         << "2: Dequeue\n"
         << "3: Is the queue empty?\n"
         << "4: Is the queue full?\n"
         << "5: Peek (front element)\n"
         << "6: Print the queue\n";

    while (true) {
        int option, ans;
        string full, empty;
        cout << "Enter choice: ";
        cin >> option;

        switch (option) {
            case 0:
                cout << "Exiting…\n";
                delete[] queueArr;
                exit(EXIT_SUCCESS);

            case 1:
                cout << "Enter value: ";
                int a;
                cin >> a;
                enqueue(a);
                cout << "Success\n";
                break;

            case 2:
                dequeue();
                cout << "Success\n";
                break;

            case 3:
                empty = (isEmpty() ? "Yes" : "No");
                cout << empty << '\n';
                break;

            case 4:
                full = (isFull() ? "Yes" : "No");
                cout << full << '\n';
                break;

            case 5:
                ans = peek();
                cout << "Front element is " << ans << '\n';
                break;

            case 6:
                printQueue();
                cout << '\n';
                break;

            default:
                cout << "Invalid\n";
        }
    }
}

bool isEmpty() {
    return (front == -1 || front > rear);
}

bool isFull() {
    return (rear == capacity - 1);
}

void enqueue(int a) {
    if (isFull()) {
        cout << "Overflow\n";
        return;
    }
    if (isEmpty()) front = 0;
    queueArr[++rear] = a;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Underflow\n";
        return;
    }
    cout << queueArr[front++] << '\n';
    if (front > rear) {
        front = rear = -1;
    }
}

int peek() {
    if (isEmpty()) {
        cout << "EMPTY QUEUE\n";
        return -1;
    }
    return queueArr[front];
}

void printQueue() {
    if (isEmpty()) {
        cout << "EMPTY QUEUE\n";
        return;
    }
    for (int i = front; i <= rear; i++) {
        cout << queueArr[i] << " ";
    }
}
