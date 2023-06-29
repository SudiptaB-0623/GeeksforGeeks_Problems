//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int pathSum(int i, int j, int n, vector<vector<int>> &dp, vector<vector<int>> matrix)
    {
        if(j<0 || j>=n)
            return -(1e9);
            
        if(dp[i][j] != -1)
            return dp[i][j];
        if(i == 0)
        {
            return dp[i][j] = matrix[i][j];
        }
        
        int up = matrix[i][j] + pathSum(i-1, j, n, dp, matrix);
        int left = matrix[i][j] + pathSum(i-1, j-1, n, dp, matrix);
        int right = matrix[i][j] + pathSum(i-1, j+1, n, dp, matrix);
        
        return dp[i][j] = max(up, max(left, right));
    }
    int maximumPath(int n, vector<vector<int>> matrix)
    {
        // code here
        int ans = INT_MIN;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        for(int j=0; j<n ; j++)
            dp[0][j] = matrix[0][j];
        
        for(int i = 1; i<n ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                int up = matrix[i][j] + dp[i-1][j];
                int left = 0, right = 0;
                if(j>0)
                    left = matrix[i][j] + dp[i-1][j-1];
                if(j<n-1)
                    right = matrix[i][j] + dp[i-1][j+1];
                
                dp[i][j] = max(up, max(left, right));
            }
            
        }
        
        for(int j=0; j<n ;j++)
            ans = max(ans, dp[n-1][j]);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends