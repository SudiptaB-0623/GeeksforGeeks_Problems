//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution 
{
  public:
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> grid)
    {
        vis[row][col] = 1;
        int drow[] = {-1, 0, 0, 1};
        int dcol[] = {0, -1, 1, 0};
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({row, col});
        
        while(!q.empty())
        {
            int nrow = q.front().first;
            int ncol = q.front().second;
            q.pop();
            for(int i=0 ; i<4 ; i++)
            {
                int r = nrow + drow[i];
                int c = ncol + dcol[i];
                if(r>=0 && r<n && c>=0 && c<m && grid[r][c]==1 && vis[r][c]==0)
                {
                    vis[r][c] = 1;
                    q.push({r, c});
                }
            }
        }
    }
    int numberOfEnclaves(vector<vector<int>> &grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;
        
        for(int j=0 ;j<m ; j++)
        {
            if(grid[0][j]==1 && vis[0][j]==0)
                bfs(0, j, vis, grid);
            if(grid[n-1][j]==1 && vis[n-1][j]==0)
                bfs(n-1, j, vis, grid);
        }
        for(int i=0 ;i<n ; i++)
        {
            if(grid[i][0]==1 && vis[i][0]==0)
                bfs(i, 0, vis, grid);
            if(grid[i][m-1]==1 && vis[i][m-1]==0)
                bfs(i, m-1, vis, grid);
        }
        
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                if(grid[i][j]==1 && vis[i][j]==0)
                    ans++;
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends