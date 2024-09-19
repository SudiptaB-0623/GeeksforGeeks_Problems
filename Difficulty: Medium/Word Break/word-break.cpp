//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings

class Solution
{
public:
bool isSafe(string s, string curr)
    {
        if(s.size()<curr.size())
            return false;
        
        for(int i=0; i<curr.size(); i++)
        {
            if(s[i] != curr[i])
                return false;
        }
        
        return true;
    }
    bool dict(int ind, string s, vector<string> &words)
    {
        if(ind >= s.size())
            return true;
        
        for(int i=0; i<words.size(); i++)
        {
            string curr = words[i];
            if(s[ind] == curr[0] && isSafe(s.substr(ind), curr))
            {
                if(dict(ind+curr.size(), s, words))
                    return true;
            }
        }
        
        return false;
    }
    int wordBreak(int n, string s, vector<string> &dictionary) 
    {
        //code here
        if(dict(0, s, dictionary))
            return 1;
            
        return 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}

// } Driver Code Ends