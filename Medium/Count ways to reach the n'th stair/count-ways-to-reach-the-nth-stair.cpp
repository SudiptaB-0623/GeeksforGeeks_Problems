//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int mod = 1e9+7;
   
    int countWays(int n)
    {
        // your code here
        int prev = 1;
        int prev2 = 1;
        
        for(int i=2; i<=n; i++)
        {
            int curr = (prev+prev2)%mod;
            prev2 = prev;
            prev = curr;
        }
        return prev%mod;
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends