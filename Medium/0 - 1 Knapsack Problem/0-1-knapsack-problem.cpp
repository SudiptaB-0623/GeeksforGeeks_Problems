//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int recur(int w, int wt[], int val[], int n, vector<vector<int>> &dp)
    {
        if(dp[n][w] != -1)
            return dp[n][w];
            
        if(n == 0)
        {
            if(wt[n] <= w)
                return val[n];
            else
                return 0;
        }
        
        int take = 0;
        if(wt[n] <= w)
            take = val[n] + recur(w-wt[n], wt, val, n-1, dp);
        int notTake = recur(w, wt, val, n-1, dp);
        
        return dp[n][w] = max(take, notTake);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n, vector<int>(W+1, -1));
       return recur(W, wt, val, n-1, dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends