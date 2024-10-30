//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution 
{
public:
    int solve(vector<int> nums, int ind, int k, vector<int> &dp)
    {
        int n = nums.size();
        
        if(ind >= n-1)
            return 0;  
        if(dp[ind] != -1)
            return dp[ind];
        
        int val=0;
        int mini=1e9;
        
        for(int i=ind; i<n; i++)
        {
            val += nums[i]; 
            int gap = i - ind;   
            
            if((val+gap<=k) && (i<n-1))
            {        
                int cost = pow(k-(val+gap), 2) + solve(nums, i+1, k, dp);
                mini = min(mini, cost);
            }
            else if((val+gap<=k) && (i==n-1))
                return dp[ind]=0;
        }
        return dp[ind]=mini;
    }
    int solveWordWrap(vector<int> nums, int k) 
    { 
        // Code here
        vector<int> dp(nums.size(), -1);
        
        return solve(nums, 0, k, dp);
    } 
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends