//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution 
{
  public:
    void dfs(int node, vector<int> adj[], vector<int> &vis)
    {
        vis[node] = 1;
        for(auto it : adj[node])
        {
            if(vis[it] != 1)
                dfs(it, adj, vis);
        }
    }
    int numProvinces(vector<vector<int>> isConnected, int n) 
    {
        // code here
        vector<int> adj[n+1];
        
        for(int i=0; i<n ; i++)
        {
            for(int j=0; j<n ; j++)
            {
                if(isConnected[i][j] == 1 && i!=j)
                    adj[i+1].push_back(j+1);
            }            
        }
        
        int prov = 0;
        vector<int> vis(n+1, 0);
        for(int i=1; i<=n ; i++)
        {
            if(vis[i] != 1)
            {
                prov++;
                dfs(i, adj, vis);
            }
        }
        return prov;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends