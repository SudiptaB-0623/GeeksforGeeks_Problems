//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    vector<vector<int>> dp(M, vector<int>(V+1, 0));
	    for(int i=0; i<=V ; i++)
	    {
	        if(i%coins[0] == 0)
	            dp[0][i] = i/coins[0];
	        else
	            dp[0][i] = 1e9;
	    }
	    
	    for(int ind=1 ; ind<M ; ind++)
	    {
	        for(int target = 0; target<=V ; target++)
	        {
	            int notTake = dp[ind-1][target];
	            int take = 1e9;
	            if(coins[ind] <= target)
	                take = 1 + dp[ind][target-coins[ind]];
	            
	            dp[ind][target] = min(take, notTake);
	        }
	    }
	    
	    if(dp[M-1][V] >= 1e9)
	        return -1;
	    else
	        return dp[M-1][V];
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends