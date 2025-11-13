#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int precedence(char c) {
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());

    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    stack<char> st;
    string result;

    for (int i = 0; i < infix.length(); i++) {
        char cur = infix[i];

        if (isalnum(cur)) {
            result += cur;
        }
        else if (cur == '(') {
            st.push(cur);
        }
        else if (cur == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop();
        }
        else { 
            while (!st.empty() && precedence(cur) < precedence(st.top())) {
                result += st.top();
                st.pop();
            }
            st.push(cur);
        }
    }

    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    reverse(result.begin(), result.end());

    return result;
}

int main() {
    string input;
    cout << "Enter your infix expression: ";
    cin >> input;

    string ans = infixToPrefix(input);
    cout << "Your prefix expression: " << ans << endl;

    return 0;
}
