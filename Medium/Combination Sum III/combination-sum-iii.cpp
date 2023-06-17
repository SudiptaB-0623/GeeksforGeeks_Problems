//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution 
{
  public:
    void comb(int num, int target, vector<int> ds, vector<vector<int>> &ans, int k)
    {
        if(target == 0 && ds.size()==k)
            ans.push_back(ds);
        if(num>9 || ds.size()>k)
            return;
        
        for(int i=num ; i<=9 ; i++)
        {
            if(i>target)
                break;
            
            ds.push_back(i);
            comb(i+1, target-i, ds, ans, k);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum(int k, int n) 
    {
        // code here
        vector<vector<int>> ans;
        vector<int> ds;
        
        comb(1, n, ds, ans, k);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K >> N;

        Solution obj;
        vector<vector<int>> ans = obj.combinationSum(K, N);
        sort(ans.begin(), ans.end());
        for (auto &arr : ans) {
            for (auto it : arr) cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends