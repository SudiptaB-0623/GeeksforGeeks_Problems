//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string s, string t)
    {
        // Your code here
        if(s.size() != t.size())
            return false;
            
        map<char, char> mpp;
        for(int i=0; i<s.size(); i++)
        {
            if(mpp.find(s[i]) != mpp.end())
            {
                if(mpp[s[i]] != t[i])
                    return false;
            }
            else
            {
                mpp[s[i]] = t[i];
            }
        }
        mpp.clear();
        for(int i=0; i<s.size(); i++)
        {
            if(mpp.find(t[i]) != mpp.end())
            {
                if(mpp[t[i]] != s[i])
                    return false;
            }
            else
            {
                mpp[t[i]] = s[i];
            }
        }
        
        return true;
        
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends