//{ Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}

// } Driver Code Ends



int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    //Your code here
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    int ans;
    
    for(int i=0; i<n ;i++)
    {
        pq.push({mat[i][0], i, 0});
    }
    
    for(int i=1 ; i<=k ; i++)
    {
        auto top = pq.top();
        pq.pop();
        ans = top[0];
        int row = top[1];
        int col = top[2];
        
        if(col+1 < n)
        {
            pq.push({mat[row][col+1], row, col+1});
        }
    }
    
    return ans;
}
