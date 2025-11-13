#include <iostream>
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
    cout << "Circular Queue Implementation\n";
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
         << "3: Is Empty?\n"
         << "4: Is Full?\n"
         << "5: Peek (front element)\n"
         << "6: Print Queue\n";

    while (true) {
        int option;
        cout << "Enter choice: ";
        cin >> option;

        switch (option) {
            case 0:
                cout << "Exiting…\n";
                delete[] queueArr;
                exit(EXIT_SUCCESS);

            case 1:{
                cout << "Enter value: ";
                int a;
                cin >> a;
                enqueue(a);
                break;
            }
            
            case 2:
                dequeue();
                break;

            case 3:{
                string empty = (isEmpty() ? "Yes" : "No");
                cout << empty << '\n';
                break;
            }
            
            case 4:{
                string full = (isFull() ? "Yes" : "No");
                cout << full << '\n';
                break;
            }
            
            case 5:{
                int ans = peek();
                if (ans != -1) cout << "Front element is " << ans << '\n';
                break;
            }
            
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
    return (front == -1);
}

bool isFull() {
    return ((rear + 1) % capacity == front);
}

void enqueue(int a) {
    if (isFull()) {
        cout << "Overflow\n";
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % capacity;
    }
    queueArr[rear] = a;
    cout << "Enqueued " << a << "\n";
}

void dequeue() {
    if (isEmpty()) {
        cout << "Underflow\n";
        return;
    }
    cout << "Dequeued " << queueArr[front] << '\n';

    if (front == rear) {
        // Queue becomes empty
        front = rear = -1;
    } else {
        front = (front + 1) % capacity;
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
    cout << "Queue elements: ";
    int i = front;
    while (true) {
        cout << queueArr[i] << " ";
        if (i == rear) break;
        i = (i + 1) % capacity;
    }
}