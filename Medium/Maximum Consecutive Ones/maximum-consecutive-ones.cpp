//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
  public:
    int longestOnes(int n, vector<int>& nums, int k) 
    {
        // Code here
        int left = 0, right = 0;
        int ans = 0;
        int z = 0;
        
        while(right<n)
        {
            if(nums[right] == 0)
            {
                z++;
            }
            
            while(z>k)
            {
                if(nums[left] == 0)
                    z--;
                left++;
            }
            
            ans = max(ans, right-left+1);
            right++;
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
        cout << obj.longestOnes(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends