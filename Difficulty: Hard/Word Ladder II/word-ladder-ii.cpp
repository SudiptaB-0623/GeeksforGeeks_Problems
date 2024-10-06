//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution 
{
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) 
    {
        // code here
        vector<vector<string>> ans;
        unordered_set<string> words(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        vector<string> wordsOnLevel;
        int level = 0;
        
        if(words.find(endWord) == words.end())
            return ans;
        q.push({beginWord});
        wordsOnLevel.push_back(beginWord);
        
        while(!q.empty())
        {
            vector<string> seq = q.front();
            q.pop();
            
            if(seq.size() > level)
            {
                if(ans.size()>0)
                    break;
                level++;
                for(auto it : wordsOnLevel)
                    words.erase(it);
                wordsOnLevel = {};
            }
            
            string word = seq[seq.size()-1];
            
            if(word == endWord)
                ans.push_back(seq);
            
            for(int i=0; i<word.size(); i++)
            {
                string temp = word;
                for(char ch='a'; ch<='z'; ch++)
                {
                    temp[i] = ch;
                    if(words.find(temp) != words.end())
                    {
                        wordsOnLevel.push_back(temp);
                        seq.push_back(temp);
                        q.push(seq);
                        seq.pop_back();
                    }
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

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
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends