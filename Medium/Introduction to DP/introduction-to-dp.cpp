//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution 
{
  public:
    long long int mod = 1e9+7;
    long long int td(int n, vector<long long int> &dp)
    {
        if(n<=1)
            return (n%mod);
        if(dp[n]!=-1)
            return dp[n]%mod;
        
        return dp[n] = (td(n-1, dp)+td(n-2, dp))%mod;
    }
    long long int topDown(int n) 
    {
        // code here
        vector<long long int> dp(n+1, -1);
        return (td(n, dp))%mod;
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