//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution 
{
  public:
    long long power(long long base, long long exp, long long mod) 
    {
        long long result = 1;
        while (exp > 0) 
        {
            if (exp % 2 == 1) 
                result = (result * base) % mod;
            base = (base * base) % mod;
            exp /= 2; 
        }
        return result;
    }

    int countgroup(vector<int>& arr) 
    {
        // Complete the function
        int xorr=0;
        long long int mod=1e9+7;
        
        for(auto x:arr)
            xorr^=x;
            
        if(xorr!=0)
            return 0;
        
        long long ans=power(2,arr.size()-1,mod)-1;
        if(ans<0)
            ans+=mod;
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
        Solution obj;
        int ans = obj.countgroup(arr);
        cout << ans << endl;
    }
}

// } Driver Code Ends