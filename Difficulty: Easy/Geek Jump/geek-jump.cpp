//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int recur(int ind, int n, vector<int>& height, vector<int> &dp)
    {
        if(ind == n-1)
            return dp[ind] = 0;
            
            if(dp[ind] != -1)
                return dp[ind];
        
        int one = INT_MAX;
        int two = INT_MAX;
        
        if(ind + 1 < n)
            one = abs(height[ind]-height[ind+1]) + recur(ind+1, n, height, dp);
        if(ind + 2 < n)
            two = abs(height[ind] - height[ind+2]) + recur(ind+2, n, height, dp);
        
        return dp[ind] = min(one, two);
    }
    int minimumEnergy(vector<int>& height, int n) 
    {
        // Code here
        vector<int> dp(n+1, -1);
        return recur(0, n, height, dp);
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
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends