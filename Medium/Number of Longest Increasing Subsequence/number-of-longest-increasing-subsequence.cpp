//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int NumberofLIS(int n, vector<int>&nums) 
    {
        // Code here
        vector<int> dp(n, 1), cnt(n, 1);
	    
        int maxi = -1;
	    for(int i=0; i<n ; i++)
	    {
	        for(int j=0; j<i ; j++)
	        {
	            if(nums[j]<nums[i] && dp[j]+1>dp[i])
                {
	                dp[i] = max(dp[i], dp[j]+1);
                    cnt[i] = cnt[j];
                }
                else if(nums[j]<nums[i] && dp[j]+1==dp[i])
                {
	                dp[i] = max(dp[i], dp[j]+1);
                    cnt[i] += cnt[j];
                }
	        }
            maxi = max(maxi, dp[i]);
	    }
	    
	    int ans = 0;
	    for(int i=0 ; i<n ; i++)
	    {
            if(dp[i] == maxi)
            {
                ans += cnt[i];
            }
	    }
	    return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        cout<<obj.NumberofLIS(n, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends