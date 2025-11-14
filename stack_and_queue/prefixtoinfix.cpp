#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

bool isOperand(char c);
string prefixToInfix(string postfix_exp);

int main(){
    string input;
    cin >> input;
    string ans = prefixToInfix(input);
    cout << ans;
}

bool isOperand(char c){
    return isalnum(c);
}

string prefixToInfix(string prefix_exp){
    reverse(prefix_exp.begin(), prefix_exp.end());
    for(int i = 0; i < prefix_exp.length(); i++){
        if(prefix_exp[i] == '('){
            prefix_exp[i] = ')';
        }
        else if(prefix_exp[i] == ')'){
            prefix_exp[i] = '(';
        }
    }
    
    stack<string> st;
    string infix_exp;
    
    for(int i = 0; i < prefix_exp.length(); i++){
        char curr = prefix_exp[i];
        
        if(isOperand(curr)) st.push(string(1, curr));
        else{
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string expr = "(" + op1 + curr + op2 + ")";
            st.push(expr);
        }
    }

    return st.top();
}