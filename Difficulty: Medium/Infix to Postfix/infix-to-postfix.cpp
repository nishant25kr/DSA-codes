//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string& s) {
    stack<char> st;
    string ans = "";
    int len = s.length();

    auto priority = [](char c) {
        if (c == '+' || c == '-') return 1;
        if (c == '*' || c == '/') return 2;
        if (c == '^') return 3;
        return 0;
    };

    for (int i = 0; i < len; i++) {
        // If character is an operand (letter or digit)
        if ((s[i] >= 'A' && s[i] <= 'Z') || 
            (s[i] >= 'a' && s[i] <= 'z') || 
            (s[i] >= '0' && s[i] <= '9')) {
            ans += s[i];
        }
        // If opening parenthesis
        else if (s[i] == '(') {
            st.push(s[i]);
        }
        // If closing parenthesis
        else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            st.pop(); // Pop the opening parenthesis
        }
        // If operator
        else {
            // Modify the while loop to handle right-associativity for '^'
            while (!st.empty() && priority(s[i])<=priority(st.top()) ) {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    // Pop all remaining operators from the stack
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    return ans;
}


};


//{ Driver Code Starts.
//  Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends