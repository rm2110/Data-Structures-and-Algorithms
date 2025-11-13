#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isOperand(char c);
string postfixToInfix(string postfix);

int main() {
    string input;
    cout << "Enter postfix expression: ";
    cin >> input;

    string infix = postfixToInfix(input);
    cout << "Equivalent infix: " << infix;
    return 0;
}

bool isOperand(char c) {
    return isalnum(c); 
}

string postfixToInfix(string postfix) {
    stack<string> st;
    char cur;

    for (int i = 0;i < postfix.length();i++) {
        char cur = postfix[i];
        
        if (isOperand(cur)) {
            st.push(string(1, cur));
        }
        else {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string expr = "(" + op2 + cur + op1 + ")";
            st.push(expr);
        }
    }
    return st.top();
}