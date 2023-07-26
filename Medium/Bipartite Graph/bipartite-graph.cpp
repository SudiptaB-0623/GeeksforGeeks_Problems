//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
public:
    bool dfs(int node, vector<int>graph[], vector<int> &vis, int col)
    {
        vis[node] = col;
        for(auto it : graph[node])
        {
            if(vis[it]==-1)
            {
                int c = (vis[node] == 0) ? 1 : 0;     
                if(dfs(it, graph, vis, c)==false)
                    return false;
            }
            else
            {
                if(vis[it] == vis[node])
                    return false;
            }                
        }
        
        return true;
    }
    
	bool isBipartite(int V, vector<int>graph[])
	{
        vector<int> vis(V, -1);
        
        for(int i=0 ; i<V ; i++)
        {
            if(vis[i] == -1)
            {
                if(dfs(i, graph, vis, 0) == false)
                    return false;
            }
        }
        
        return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends