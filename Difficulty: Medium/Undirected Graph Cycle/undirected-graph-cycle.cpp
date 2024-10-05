//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int node, vector<int> adj[], int fromNode, vector<int> &vis)
    {
        vis[node] = 1;
        
        for(auto it : adj[node])
        {
            if(vis[it] == 0)
            {
                if(dfs(it, adj, node, vis))
                    return true;
            }
            else if(vis[it]==1 && it!=fromNode)
                return true;
        }
        
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) 
    {
        // Code here
        vector<int> vis(V, 0);
        bool ans;
        
        for(int i=0; i<V; i++)
        {
            if(vis[i] == 0)
            {
                ans = dfs(i, adj, i, vis);
                if(ans == true)
                    return true;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends