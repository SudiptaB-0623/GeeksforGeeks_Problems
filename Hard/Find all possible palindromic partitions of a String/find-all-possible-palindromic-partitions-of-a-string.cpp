//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution 
{
  public:
    bool isPalin(int start, int end, string s)
    {
        while(start<=end)
        {
            if(s[start]!=s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    void solve(int ind, vector<string> &ds, vector<vector<string>> &ans, string s)
    {
        if(ind == s.size())
        {
            ans.push_back(ds);
            return;
        }
        
        for(int i=ind; i<s.size() ; i++)
        {
            if(isPalin(ind, i, s))
            {
                string temp = s.substr(ind, i-ind+1);
                ds.push_back(temp);
                solve(i+1, ds, ans, s);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> allPalindromicPerms(string S) 
    {
        // code here
        vector<vector<string>> ans;
        vector<string> ds;
        
        solve(0, ds, ans, S);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends