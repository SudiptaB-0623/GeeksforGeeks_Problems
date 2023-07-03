//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution
{   
public:
    bool subSet(int ind, int target, vector<int> arr, vector<vector<int>> &dp)
    {
        if(dp[ind][target] != -1)
            return dp[ind][target];
            
        if(target == 0)
            return dp[ind][target] = true;
        
        if(ind == 0)
            return dp[ind][target] = (target == arr[0]);
        
        bool taken = false;
        if(arr[ind]<=target)
            taken = subSet(ind-1, target-arr[ind], arr, dp);
        
        if(taken == true)       //If taken is true, no need to check for not true as we need only one such subset
            return dp[ind][target] = true;
        
        bool not_taken = subSet(ind-1, target, arr, dp);
        
        return dp[ind][target] = (taken||not_taken);
    }
    bool isSubsetSum(vector<int>arr, int sum)
    {
        // code here 
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return subSet(n-1, sum, arr, dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends