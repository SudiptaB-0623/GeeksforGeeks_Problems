//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        // code here 
        string ans = "";
        string word = "";
        int n = s.size();
        
        for(int i=0 ; i<n ; i++)
        {
            if(s[i] == '.')
                continue;
            
            word = "";
            while(i<n)
            {
                word = word+s[i];
                i++;
                if(i!=n && s[i] == '.')
                    break;
            }
            
            if(ans.size()==0)
                ans = word;
            else
                ans = word + '.' + ans;
        }
        
        return ans;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends