//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
  public:
    static bool comp(pair<int, int> p1, pair<int, int> p2)
    {
        if(p2.second == p1.second)
            return p1.first > p2.first;
        
        return p1.second > p2.second;
    }
    vector<int> topK(vector<int>& nums, int k) 
    {
        // Code here
        vector<int> ans;
        unordered_map<int, int> mpp;
        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]]++;
        }
        vector<pair<int, int>> vec(mpp.begin(), mpp.end());
        
        sort(vec.begin(), vec.end(), comp);
        
        for(int i=0; i<k ; i++)
        {
            ans.push_back(vec[i].first);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends