//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
public:
    void dfs(int sr, int sc, vector<vector<int>> &floodFill, int currColor, int newColor, vector<vector<int>> &vis)
    {
        floodFill[sr][sc] = newColor;
        vis[sr][sc] = 1;
        int n = floodFill.size();
        int m = floodFill[0].size();
        
        if(sr-1>=0 && vis[sr-1][sc]==0 && floodFill[sr-1][sc]==currColor)
            dfs(sr-1, sc, floodFill, currColor, newColor, vis);
            
        if(sr+1<n && vis[sr+1][sc]==0 && floodFill[sr+1][sc]==currColor)
            dfs(sr+1, sc, floodFill, currColor, newColor, vis);
            
        if(sc-1>=0 && vis[sr][sc-1]==0 && floodFill[sr][sc-1]==currColor)
            dfs(sr, sc-1, floodFill, currColor, newColor, vis);
            
        if(sc+1<m && vis[sr][sc+1]==0 && floodFill[sr][sc+1]==currColor)
            dfs(sr, sc+1, floodFill, currColor, newColor, vis);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        // Code here 
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> floodFill = image;
        int currColor = image[sr][sc];
        
        dfs(sr, sc, floodFill, currColor, newColor, vis);
        
        return floodFill;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends