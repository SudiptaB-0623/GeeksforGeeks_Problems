//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool recur(int ind, int i, int j, vector<vector<char>> &board, string word)
    {
        if(ind+1 == word.size())
            return true;
        
        if(i>0 && board[i-1][j]==word[ind+1])
        {
            //up
            char c = board[i-1][j];
            board[i-1][j] = '#';
            if(recur(ind+1, i-1, j, board, word))
                return true;
            board[i-1][j] = c;
        }
                
        if(j>0 && board[i][j-1]==word[ind+1])
        {
            //left
            char c = board[i][j-1];
            board[i][j-1] = '#';
            if(recur(ind+1, i, j-1, board, word))
                return true;
            board[i][j-1] = c;
        }
        
        if(i<board.size()-1 && board[i+1][j]==word[ind+1])
        {
            //down
            char c = board[i+1][j];
            board[i+1][j] = '#';
            if(recur(ind+1, i+1, j, board, word))
                return true;
            board[i+1][j] = c;
        }
                
        if(j<board[0].size()-1 && board[i][j+1]==word[ind+1])
        {
            //right
            char c = board[i][j+1];
            board[i][j+1] = '#';
            if(recur(ind+1, i, j+1, board, word))
                return true;
            board[i][j+1] = c;
        }
        
        return false;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[0].size(); j++)
            {
                if(board[i][j] == word[0])
                {   
                    char c = board[i][j];
                    board[i][j] = '#';
                    if(recur(0, i, j, board, word))
                        return true; 
                    board[i][j] = c;
                }
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends