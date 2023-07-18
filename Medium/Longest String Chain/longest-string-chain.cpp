//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

bool comp(string &s1, string &s2)
{
    return s1.size()<s2.size();
}
class Solution 
{
  public:
    
    bool compare(string &s1, string &s2)
    {
        if(s2.size()-s1.size() != 1)
            return false;
        
        int n = s1.size();
        int m = s2.size();
        int i=0, j=0;
        
        while(i<n && j<m)
        {
            if(s1[i] == s2[j])
            {
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        if(i==n)        //j==m is not considered because think of s1=ab & s2=abc
            return true;
        return false;
    }
    int longestChain(int n, vector<string>& words) 
    {
        // Code here
        sort(words.begin(), words.end(), comp);
        
        int maxi = -1;
        vector<int> dp(n, 1);
        for(int i=0; i<n ; i++)
        {
            for(int j=0; j<i ; j++)
            {
                if(compare(words[j], words[i]) && dp[j]+1>dp[i])
                {
                    dp[i] = dp[j]+1;
                }
            }
            maxi = max(maxi, dp[i]);
        }
        
        return maxi;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> words(N);
        for (int i = 0; i < N; i++) {
            cin >> words[i];
        }
        Solution obj;
        cout << obj.longestChain(N, words) << "\n";
    }
    return 0;
}
// } Driver Code Ends