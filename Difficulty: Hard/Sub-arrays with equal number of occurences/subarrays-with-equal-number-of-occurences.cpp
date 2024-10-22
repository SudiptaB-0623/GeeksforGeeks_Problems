//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution 
{
  public:
    int sameOccurrence(vector<int>& arr, int x, int y) 
    {
        // code here
        int n = arr.size();
        vector<int> xFreq(n);
        vector<int> yFreq(n);
        vector<int> diff(n);
        unordered_map<int,int> mpp;
        
        xFreq[0] = (arr[0] == x) ? 1 : 0;
        yFreq[0] = (arr[0] == y) ? 1 : 0;
        diff[0] = xFreq[0]-yFreq[0];
        
        for(int i=1; i<n; i++)
        {
            if(arr[i] == x)
                xFreq[i] = 1 + xFreq[i-1];
            else
                xFreq[i] = xFreq[i-1];
            
            if(arr[i] == y)
                yFreq[i] = 1 + yFreq[i-1];
            else
                yFreq[i] = yFreq[i-1];
            
            diff[i] = xFreq[i]-yFreq[i];
        }
        
        for(int i=0;i<diff.size();i++)
            mpp[diff[i]]++;
        
        long long ans = mpp[0];
        
        for(auto it: mpp)
        {
            long long freq = it.second;
            ans += (freq*(freq-1))/2LL;
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
        int x = stoi(ks);
        string ks1;
        getline(cin, ks1);
        int y = stoi(ks1);
        Solution ob;
        int ans = ob.sameOccurrence(arr, x, y);
        cout << ans << "\n";
        // cout<<"~"<<endl;
    }
    return 0;
}
// } Driver Code Ends