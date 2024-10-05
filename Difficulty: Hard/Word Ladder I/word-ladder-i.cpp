//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
public:
    int wordLadderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        // Code here
        unordered_set<string> words(wordList.begin(), wordList.end());
        if(words.find(endWord) == words.end())
            return 0;
        
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        if(words.find(beginWord) != words.end())
            words.erase(beginWord);
        
        while(!q.empty())
        {
            string word = q.front().first;
            int level = q.front().second;
            q.pop();
            
            if(word == endWord)
                return level;
            
            for(int i=0; i<word.size(); i++)
            {
                string temp = word;
                for(char ch='a'; ch<='z'; ch++)
                {
                    temp[i] = ch;
                    if(words.find(temp) != words.end())
                    {
                        q.push({temp, level+1});
                        words.erase(temp);
                    }
                }
            }
        }
        
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends