//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution 
{
  public:
    bool dfsCheck(int node, vector<int> &vis, vector<int> &path, vector<int> &check, vector<int> graph[])
    {
        vis[node] = 1;
        path[node] = 1;
        
        for(auto it : graph[node])
        {
            if(vis[it] == 0)
            {
                if(dfsCheck(it, vis, path, check, graph) == true)
                {
                    return true;
                }                
            }
            else if(path[it] == 1)
            {
                return true;
            }
        }
        
        path[node] = 0;
        check[node] = 1;
        
        return false;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) 
    {
        // code here
        vector<int> vis(V, 0);
        vector<int> path(V, 0);
        vector<int> check(V, 0);
        
        vector<int> ans;
        
        for(int i=0 ; i<V ; i++)
        {
            if(vis[i]!=1)
            {
                dfsCheck(i, vis, path, check, adj);
            }
        }
        
        for(int i=0 ; i<V ; i++)
        {
            if(check[i] == 1)
                ans.push_back(i);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends