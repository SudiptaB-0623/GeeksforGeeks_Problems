//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int longestUniqueSubsttr(string s)
    {
        //code
        vector<int> alpha(26, 0);
        int left = 0, right = 0;
        int n = s.size();
        int ans = 0;
        
        while(right<n)
        {
            alpha[s[right] - 'a']++;
            while(alpha[s[right] - 'a'] > 1)
            {
                alpha[s[left] - 'a']--;
                left++;
            }
            
            ans = max(ans, right-left+1);
            right++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends