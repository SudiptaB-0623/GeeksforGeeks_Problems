//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int subSet(int ind, int target, int arr[], vector<vector<int>> &dp)
    {
        if(dp[ind][target] != -1)
            return dp[ind][target];
        if(target == 0)
            return dp[ind][target] = 1;
        if(ind == 0)
            return dp[ind][target] = (arr[ind] == target);
        
        int take = 0;
        if(target>=arr[ind])
            take = subSet(ind-1, target-arr[ind], arr, dp);
        
        if(take == 1)
            return dp[ind][target] = 1;
        
        int not_take = subSet(ind-1, target, arr, dp);
        
        return dp[ind][target] = (take||not_take);
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for(int i=0;i<N;i++)
            sum += arr[i];
        
        if(sum%2 == 1)
            return 0;
        vector<vector<int>> dp(N, vector<int>((sum/2)+1, -1));
        return subSet(N-1, sum/2, arr, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends