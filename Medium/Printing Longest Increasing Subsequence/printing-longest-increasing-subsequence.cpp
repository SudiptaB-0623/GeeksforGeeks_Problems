//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution 
{
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) 
    {
        // Code here
        vector<int> ans;
        vector<int> dp(n, 1), loc(n, -1);
        int maxi = -1;
        
        for(int i=0; i<n ; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(arr[j]<arr[i] && dp[j]+1 > dp[i])
                {
                    dp[i] = dp[j]+1;
                    loc[i] = j;
                }
            }
            maxi = max(maxi, dp[i]);
        }
        
        int ind = -1;
        for(int i=0; i<n ; i++)
        {
            if(dp[i] == maxi)
            {
                ind = i;
                break;
            } 
        }
        
        while(ind>=0)
        {
            ans.push_back(arr[ind]);
            if(ind == loc[ind])
                break;
            ind = loc[ind];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends