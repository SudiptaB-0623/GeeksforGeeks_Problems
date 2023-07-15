//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
    int wildCard(int ind1, int ind2, string s, string p, vector<vector<int>> &dp)
    {
        if(ind1<0 && ind2<0)
            return 1;
        if(ind1<0 && ind2>=0)
            return 0;
        if(ind2<0 && ind1>=0)
        {
            while(ind1>=0)
            {
                if(s[ind1] != '*')
                    return 0;
                ind1--;
            }
            return 1;
        }
        
        if(dp[ind1][ind2] != -1)
            return dp[ind1][ind2];
        if(s[ind1] == p[ind2]  || s[ind1] == '?')
            return dp[ind1][ind2] = wildCard(ind1-1, ind2-1, s, p, dp);
        else
        {
            if(s[ind1] == '*')
                return dp[ind1][ind2] = (wildCard(ind1, ind2-1, s, p, dp) || wildCard(ind1-1, ind2, s, p, dp));
            return 0;
        }
    }
    int wildCard(string pattern,string str)
    {
        int n = pattern.size();
        int m = str.size();
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        return wildCard(n-1, m-1, pattern, str, dp);
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends