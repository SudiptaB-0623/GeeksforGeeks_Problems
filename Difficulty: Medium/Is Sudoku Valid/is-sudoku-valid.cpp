//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    bool isSafe(vector<vector<int>> &board, int m, int n, int c)
    {
        for(int i=0; i<=8; i++)
        {
            if(board[i][n] == c && i!=m)
                return false;
            
            if(board[m][i] == c && i!=n)
                return false;
            
            int row = 3*(m/3) + i/3;
            int col = 3*(n/3) + i%3;
            
            if(board[row][col] == c && (row!=m && col!=n))
                return false;
        }
        
        return true;
    }
    int isValid(vector<vector<int>> mat)
    {
        // code here
        for(int i=0; i<=8; i++)
        {
            for(int j=0; j<=8; j++)
            {
                if(mat[i][j] != 0)
                {
                    if(isSafe(mat, i, j, mat[i][j]) != true)
                        return false;
                }
            }
        }
        
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends