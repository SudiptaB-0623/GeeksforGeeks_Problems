//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution 
{
  public:
    void recur(int n, map<int, int> mpp, vector<vector<int>> &ans, vector<int> ds)
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
                ds.push_back(it.first);
                mpp[it.first]--;
                recur(n, mpp, ans, ds);
                mpp[it.first]++;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> uniquePerms(vector<int> &nums ,int n) 
    {
        // code here
        vector<vector<int>> ans;
        map<int, int> mpp;
        vector<int> ds;
        
        for(int i=0; i<n; i++)
            mpp[nums[i]]++;
        
        recur(n, mpp, ans, ds);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends