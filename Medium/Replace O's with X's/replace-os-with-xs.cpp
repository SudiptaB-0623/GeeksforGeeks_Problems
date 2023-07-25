//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> board)
    {
        vis[row][col] = 1;
        int drow[] = {-1, 0, 0, 1};
        int dcol[] = {0, -1, 1, 0};
        int n = board.size();
        int m = board[0].size();
        
        for(int i=0 ; i<4 ; i++)
        {
            int r = row + drow[i];
            int c = col + dcol[i];
            if(r>=0 && r<n && c>=0 && c<m && board[r][c]=='O' && vis[r][c]==0)
            {
                dfs(r, c, vis, board);
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<char>> board = mat;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for(int j=0 ;j<m ; j++)
        {
            if(board[0][j]=='O' && vis[0][j]==0)
                dfs(0, j, vis, board);
            if(board[n-1][j]=='O' && vis[n-1][j]==0)
                dfs(n-1, j, vis, board);
        }
        for(int i=0 ;i<n ; i++)
        {
            if(board[i][0]=='O' && vis[i][0]==0)
                dfs(i, 0, vis, board);
            if(board[i][m-1]=='O' && vis[i][m-1]==0)
                dfs(i, m-1, vis, board);
        }
        
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                if(board[i][j]=='O' && vis[i][j]==0)
                    board[i][j] = 'X';
            }
        }
        
        return board;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends