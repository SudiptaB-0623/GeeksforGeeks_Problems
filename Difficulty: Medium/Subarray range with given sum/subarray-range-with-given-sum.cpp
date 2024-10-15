//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution 
{
  public:
    // Function to count the number of subarrays which adds to the given sum.
    int subArraySum(vector<int>& arr, int tar) 
    {
        // Your code here
        int ans = 0;
        map<int, int> mpp;
        mpp[0] = 1;
        int sum = 0;
        
        for(int i=0; i<arr.size(); i++)
        {
            sum += arr[i];
            if(mpp.find(sum-tar) != mpp.end())
            {
                ans += mpp[sum-tar];
            }
            if(mpp.find(sum) != mpp.end())
                mpp[sum]++;
            else
                mpp[sum] = 1;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int tar = stoi(ks);
        Solution obj;
        int res = obj.subArraySum(arr, tar);
        cout << res << endl;
    }
    return 0;
}
// } Driver Code Ends