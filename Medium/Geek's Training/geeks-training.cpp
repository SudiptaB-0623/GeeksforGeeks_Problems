//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
  public:
    int geek_train(int day, int last, vector<vector<int>>& points, vector<vector<int>> &dp)
    {
        if(dp[day][last] != -1)
            return dp[day][last];
        if(day == 0)
        {
            int maxi = 0;
            for(int i=0; i<3 ; i++)
            {
                if(i!=last)
                {
                    maxi = max(points[0][i], maxi);
                }
            }
            return dp[day][last] = maxi;
        }
            
        int maxi = 0;
        for(int i=0; i<3; i++)
        {
            if(i!=last)
            {
                int point = points[day][i] + geek_train(day-1, i, points, dp);
                maxi = max(point, maxi);
            }
        }
        return dp[day][last] = maxi;
    }
    int maximumPoints(vector<vector<int>>& points, int n) 
    {
        // Code here
        vector<vector<int>> dp(n, vector<int>(4, -1));
        
        return geek_train(n-1, 3, points, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends