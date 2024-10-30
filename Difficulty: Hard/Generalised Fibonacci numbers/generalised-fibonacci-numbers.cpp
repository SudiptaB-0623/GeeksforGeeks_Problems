//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
  public:
    vector<vector<long long>> multiply(vector<vector<long long>> grid1, vector<vector<long long>> grid2, long long m)
    {
        vector<vector<long long>> ans(3, vector<long long>(3, 0));
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                for(int k=0; k<3; k++)
                {
                    ans[i][j] = (ans[i][j] + (grid1[i][k]*grid2[k][j])) % m;
                }
            }
        }
        return ans;
    }
    vector<vector<long long>> matMul(vector<vector<long long>> grid, long long n, long long m)
    {
        if(n==1)
            return grid;
            
        vector<vector<long long>> prod = matMul(grid, n/2, m);
        prod = multiply(prod, prod, m);
        
        if(n%2 == 1)
            prod=multiply(prod, grid, m);
            
        return prod;
    }
    long long genFibNum(long long a, long long b, long long c, long long n, long long m) 
    {
        // code here
        if(n<=2)
            return 1;
            
        vector<vector<long long>> grid(3, vector<long long>(3, 0));
        grid[0][0]=a;
        grid[0][1]=b;
        grid[0][2]=1;
        grid[1][0]=1;
        grid[2][2]=1;
        
        grid = matMul(grid, n-2, m);
        
        return (grid[0][0] + grid[0][1] + (c*grid[0][2])) % m;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long a,b,c,n,m;
        
        cin>>a>>b>>c>>n>>m;

        Solution ob;
        cout << ob.genFibNum(a,b,c,n,m) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends