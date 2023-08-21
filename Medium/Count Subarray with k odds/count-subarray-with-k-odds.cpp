//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
  public:
    int countSubarray(int n, vector<int>& nums, int k) 
    {
        // Code here
        int ans = 0;
        
        vector<int> temp;
        for(int i=0 ; i<n ; i++)
        {
            temp.push_back(nums[i]%2);
        }
        
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int sum = 0;
        for(int i=0 ; i<n ; i++)
        {
            sum += temp[i];
            if(mpp.find(sum-k) != mpp.end())
                ans += mpp[sum-k];
            
            mpp[sum]++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.countSubarray(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends