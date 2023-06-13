//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{   
public:
    int countSmallerThanMid(vector<int> &row, int mid)
    {
        int l = 0, r = row.size()-1;
        
        while(l <= r)
        {
            int m = (l+r)>>1;
            if(row[m] <= mid)
                l = m+1;
            else
                r = m-1;
        }
        return l;
    }
    
    int median(vector<vector<int>> &matrix, int R, int C)
    {
        // code here 
        // int low = matrix[0][0], high = matrix[0][C-1];
        // for(int i=1;i<R;i++)
        // {
        //     if(low>matrix[i][0])
        //         low = matrix[i][0];
        // }
        // for(int i=1;i<R;i++)
        // {
        //     if(high<matrix[C-1][i])
        //         high = matrix[C-1][i];
        // }
        int low = 1, high = 1e9;
        
        while(low<=high)
        {
            int mid = (high+low)>>1;
            
            int count = 0;
            
            for(int i=0 ; i<R ; i++)
            {
                count += countSmallerThanMid(matrix[i], mid);
            }
            
            if(count <= (R*C)/2)
            {
                low = mid+1;
            }
            else
                high = mid - 1;
        }
        return low;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends