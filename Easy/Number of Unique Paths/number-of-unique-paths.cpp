//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    //Function to find total number of unique paths.
    int paths(int a, int b, vector<vector<int>> &dp)
    {
        if(a==0 && b==0)
            return dp[a][b] = 1;
        
        if(a<0 || b<0)
            return 0;
            
        if(dp[a][b] != -1)
            return dp[a][b];
            
        int left = paths(a, b-1, dp);
        int right = paths(a-1, b, dp);
        
        return dp[a][b] = left+right;
    }
    int NumberOfPath(int a, int b)
    {
        //code here
        vector<int> prev(b, 0);
        
        for(int i = 0; i<a ; i++)
        {
            vector<int> temp(b, 0);
            for(int j = 0; j<b ; j++)
            {
                if(i==0 && j==0)
                    temp[j] = 1;
                else
                {
                    int left = 0;
                    int up = 0;
                    if(j>0)
                    {
                        left = temp[j-1];
                    }
                    if(i>0)
                    {
                        up = prev[j];
                    }
                    
                    temp[j] = left + up;
                }
            }
            prev = temp;
        }
        return prev[b-1];
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}


// } Driver Code Ends