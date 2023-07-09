//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution 
{
  public:
    // Function to convert an infix expression to a postfix expression.
    int prec(char c)
    {
        if(c == '^')
            return 3;
        else if( c == '/' || c == '*' )
            return 2;
        else if( c == '+' || c == '-' )
            return 1;
        else 
            return -1;
    }
    string infixToPostfix(string s) 
    {
        // Your code here
        stack<char> st;
        string ans = "";
        
        for(int ind=0; ind<s.size() ; ind++)
        {
            if((s[ind]>='a' && s[ind]<='z') || (s[ind]>='A' && s[ind]<='Z') || (s[ind]>='0' && s[ind]<='9'))
            {
                ans += s[ind];
            }
            else if(s[ind] == '(')
                st.push(s[ind]);
            else if(s[ind] == ')')
            {
                while(!st.empty())
                {
                    if(st.top() == '(')
                    {
                        st.pop();
                        break;
                    }
                    char c = st.top();
                    st.pop();
                    ans += c;
                }
            }
            else
            {
                if(st.empty() || st.top()=='(' || prec(s[ind]) > prec(st.top()))
                    st.push(s[ind]);
                else
                {
                    while(!st.empty() && prec(s[ind])<=prec(st.top() ))
                    {
                        char c = st.top();
                        st.pop();
                        ans += c;
                    }
                    st.push(s[ind]);
                }
            }
        }
        
        while(!st.empty())
        {
            char c = st.top();
            ans += c;
            st.pop();
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends