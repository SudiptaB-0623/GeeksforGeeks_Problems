//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long int atMax(string s, int k, int n)
    {
        long long int dist = 0;
        long long int ans = 0;
        int i=0 , j=0;
        vector<int> alpha(26, 0);
        
        while(j<n)
        {
            if(alpha[s[j]-'a'] == 0)
                dist++;
            alpha[s[j]-'a']++;
            
            while(dist>k)
            {
                alpha[s[i]-'a']--;
                if(alpha[s[i]-'a'] == 0)
                    dist--;
                i++;
            }
            
            ans += j-i+1;
            j++;
        }
        
        return ans;
    }
    long long int substrCount (string s, int k) 
    {
    	//code here.
    	int n = s.size();
    	
    	return atMax(s, k, n)-atMax(s, k-1, n);
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends