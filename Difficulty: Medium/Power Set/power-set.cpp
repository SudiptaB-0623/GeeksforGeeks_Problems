//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	void subSeq(int ind, string s, vector<string> &sqs, string temp)
	{
	    if(ind >= s.size())
	    {
	        if(temp.size() == 0)
	            return;
	        sqs.push_back(temp);
	        return;
	    }
	    
	    temp += s[ind];
	    subSeq(ind+1, s, sqs, temp);
	    temp.erase(temp.size()-1);
	    subSeq(ind+1, s, sqs, temp);
	}
	vector<string> AllPossibleStrings(string s)
	{
	    // Code here
	    vector<string> ans;
	    string temp = "";
	    subSeq(0, s, ans, temp);
	    
	    sort(ans.begin(), ans.end());
	    
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends