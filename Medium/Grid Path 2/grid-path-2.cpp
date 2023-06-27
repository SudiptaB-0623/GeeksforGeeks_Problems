//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
  public:
    int totalWays(int a, int b, vector<vector<int>>& Grid) 
    {
        // Code here
        int mod = 1e9+7;
        
        if(Grid[0][0] == 1 || Grid[a-1][b-1] == 1)
            return 0;
        
        vector<vector<int>> dp(a, vector<int>(b, -1));
        
        for(int i = 0; i<a ; i++)
        {
            for(int j = 0; j<b ; j++)
            {
                if(i==0 && j==0)
                    dp[i][j] = 1%mod;
                else if(Grid[i][j] == 1)
                {
                    dp[i][j] = 0%mod;
                }
                else
                {
                    int left = 0;
                    int up = 0;
                    if(j>0)
                        left = dp[i][j-1]%mod;
                    if(i>0)
                        up = dp[i-1][j]%mod;
                    
                    dp[i][j] = (left + up)%mod;
                }
            }
        }
        return dp[a-1][b-1]%mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < m; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.totalWays(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends