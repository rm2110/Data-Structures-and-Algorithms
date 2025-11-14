#include <iostream>
#include <string>
using namespace std;

int top = -1;

void reverseString(string s, int size){
    char stack[size];

    for (int i = 0; i < s.length(); i++) {
        char cur = s[i];
        stack[++top] = cur;
    }

    while (top >= 0) {
        cout << stack[top--];
    }
}

int main() {
    string inputStr;
    cout << "Enter your string: ";
    cin >> inputStr;
    int n = inputStr.length();

    cout << "Your reversed string is: ";
    reverseString(inputStr, n);

    return 0;
}
