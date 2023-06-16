//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    void  power(int ind, string s, string temp, int size, vector<string> &ans)
	    {
	        if(ind == size)
	        {
	            if(temp.size() == 0)
	                return;
	            ans.push_back(temp);
	            return;
	        }
	        temp = temp + s[ind];
	        power(ind+1, s, temp, size, ans);
	        temp.erase(temp.size()-1);
	        power(ind+1, s, temp, size, ans);
	    }
		vector<string> AllPossibleStrings(string s)
		{
		    // Code here
		    vector<string> ans;
		    int n = s.size();
		    string temp = {};
		    power(0, s, temp, n, ans);
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