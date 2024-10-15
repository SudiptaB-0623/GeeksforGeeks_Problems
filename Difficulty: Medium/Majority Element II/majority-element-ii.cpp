//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution 
{
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& arr) 
    {
        // Your code goes here.
        int n = arr.size();
        vector<int> ans;
        map<int, int> mpp;
        
        for(auto num : arr)
        {
            mpp[num]++;
        }
        for(auto ele : mpp)
        {
            if(ele.second > n/3)
                ans.push_back(ele.first);
        }
        
        if(ans.size() == 0)
            return {-1};
            
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends