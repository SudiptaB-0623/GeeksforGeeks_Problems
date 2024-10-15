//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution 
{
  public:
    int maxDistance(vector<int> &arr) 
    {
        // Code here
        int n = arr.size();
        map<int, int> mpp;
        int ans = 0;
        
        for(int i=0; i<n; i++)
        {
            if(mpp.find(arr[i]) == mpp.end())
            {
                mpp[arr[i]] = i;
            }
            else
            {
                int diff = i - mpp[arr[i]];
                ans = max(ans, diff);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);

        stringstream s1(input);
        int num;
        while (s1 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxDistance(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends