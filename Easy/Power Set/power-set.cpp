//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    void subseq(string s, string sub, vector<string> &ans)
	    {
	        ans.push_back(s);
	        
	        if(sub.size()==0)
	        {
	            return;
	        }
	        
	        
	        for(int i=0;i<sub.size();i++)
	        {
	            string temp = s + sub[i];
	            string temp2 = sub.substr(i+1);
	            subseq(temp, temp2, ans);
	        }
	    }
		vector<string> AllPossibleStrings(string s)
		{
		    // Code here
		    vector<string> ans;
		    
		    for(int i=0;i<s.size();i++)
		    {
		        string sub = s.substr(i+1);
		        string a = s.substr(i ,1);
		        //cout<<a<<" "<<sub<<endl;
		        subseq(a, sub, ans);
		    }
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