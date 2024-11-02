//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution 
{
  public:

    bool checkDuplicatesWithinK(vector<int>& arr, int k) 
    {
        // your code
        int n = arr.size();
        unordered_map<int, int> mpp;
        
        for(int i=0; i<=k; i++)
        {
            mpp[arr[i]]++;
            if(mpp[arr[i]] > 1)
                return true;
        }
        
        for(int i=k+1, j=0; i<n; i++, j++)
        {
            mpp[arr[j]]--;
            if(mpp[arr[j]] == 0)
                mpp.erase(arr[j]);
            
            mpp[arr[i]]++;
            if(mpp[arr[i]] > 1)
                return true;
        }
        
        return false;
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
        int k = stoi(ks);
        Solution obj;
        bool res = obj.checkDuplicatesWithinK(arr, k);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends