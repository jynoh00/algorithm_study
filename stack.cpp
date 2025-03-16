#include <iostream>
#include <string>
#include <stack>

#define MAX 100
using namespace std;

bool isBalanced(string str){
    stack<char> st;

    for (char ch : str){
        if (ch == '(' || ch == '{' || ch == '['){
            st.push(ch);
        }else if ( ch == ')' || ch == '}' || ch == ']'){
            if (st.empty()) return false;
            char top = st.top();
            st.pop();
            if ( (ch == ')' && top != '(') || (ch == '}' && top != '{') || (ch == ']' && top != '[')){
                return false;
            }
        }
    }

    return st.empty();
}

int main(){
    string str = "(((({{}}))))[[]][()]";
    cout << isBalanced(str) << endl;
}