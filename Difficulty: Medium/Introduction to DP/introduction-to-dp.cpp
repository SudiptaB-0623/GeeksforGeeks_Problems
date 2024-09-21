//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long mod = 1e9 + 7;
    long long mem(int ind, vector<long long int> &dp)
    {
        if(ind <= 1)
            return dp[ind] = ind;
        
        if(dp[ind] != -1)
            return dp[ind]%mod;
            
        return dp[ind] = (mem(ind-1, dp) + mem(ind-2, dp))%mod;
    }
    long long int topDown(int n) 
    {
        // code here
        vector<long long int> dp(n+1, -1);
        
        return (mem(n, dp))%mod;
    }
    long long int bottomUp(int n) 
    {
        // code here
        long long int prev2 = 0;
        long long int prev = 1;
        
        for(int i = 2; i<=n; i++)
        {
            long long int curr = (prev+prev2)%mod;
            prev2 = prev;
            prev = curr;
        }
        
        return prev%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends