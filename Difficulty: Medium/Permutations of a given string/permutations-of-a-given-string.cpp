//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
    	void recur(int n, map<char, int> mpp, vector<string> &ans, string ds)
        {
            if(ds.size() == n)
            {
                ans.push_back(ds);
                return;
            }
            for(auto it : mpp)
            {
                if(it.second > 0)
                {
                    ds = ds + it.first;
                    mpp[it.first]--;
                    recur(n, mpp, ans, ds);
                    mpp[it.first]++;
                    ds.erase(ds.size()-1);
                }
            }
        }
		vector<string>find_permutation(string str)
		{
		    // Code here there
		    vector<string> ans;
            map<char, int> mpp;
            string ds = "";
            
            for(int i=0; i<str.size(); i++)
                mpp[str[i]]++;
            
            recur(str.size(), mpp, ans, ds);
            
            return ans;
		    
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends