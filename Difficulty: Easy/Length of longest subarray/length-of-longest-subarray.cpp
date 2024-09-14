//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution 
{
    /* Function that returns the longest subarray
       of non-negative integers */
  public:
    int longestSubarry(vector<int>& arr) 
    {
        // write code here
        int ans = 0;
        int currSt = 0;
        
        for(int i=0; i<arr.size(); i++)
        {
            if(arr[i]>=0)
                currSt++;
            else
            {
                ans = max(ans, currSt);
                currSt = 0;
            }
        }
        
        return max(ans, currSt);
    }
};

//{ Driver Code Starts.
//   Driver code
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
        Solution ob;
        cout << ob.longestSubarry(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends