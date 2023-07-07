//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

  public:
	int minDifference(int arr[], int n)  
	{ 
	    int totSum = 0;
	    for(int i=0 ; i<n ; i++)
	        totSum += arr[i];
        
        vector<vector<bool>> dp(n, vector<bool>(totSum+1, false));
        for(int i=0 ; i<n ; i++)
            dp[i][0] = true;
        
        if(arr[0] <= totSum)
            dp[0][arr[0]] = true;
        
        for(int ind=1 ; ind<n ; ind++)
        {
            for(int target=1; target<=totSum ; target++)
            {
                bool notTake = dp[ind-1][target];
                bool take = 0;
                if(target>=arr[ind])
                    take = dp[ind-1][target-arr[ind]];
                
                dp[ind][target] = take|notTake;
            }
        }
        
        int mini = INT_MAX;
        for(int i = 0 ; i<=totSum/2 ; i++)
        {
            if(dp[n-1][i] == true)
            {
                int s1 = i;
                int diff = abs(s1 - (totSum-s1));
                mini = min(mini, diff);
            }
        }
        
        return mini;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends