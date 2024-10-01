//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> arr, int k) 
    {
        // Code here.
        if(arr.size()%2 == 1)
            return false;
            
        map<int, int> remCount;
        
        for(int i=0; i<arr.size(); i++)
            remCount[((arr[i]%k)+k)%k]++;
        
        for(int i=0; i<arr.size(); i++)
        {
            int rem = ((arr[i]%k)+k)%k;
            
            if(rem == 0)
            {
                if(remCount[rem]%2 == 1)
                    return false;
            }
            else if(remCount[rem] != remCount[k-rem])
                return false;
        }
        
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends