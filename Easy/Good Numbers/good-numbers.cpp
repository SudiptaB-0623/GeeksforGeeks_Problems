//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution 
{
  public:
    bool check(int num, int d)
    {
        int sum = num%10;
        num /= 10;
        
        if(sum == d)
        {
            return false;
        }
        
        
        while(num!=0)
        {
            int digit = num%10;
            num /= 10;
            if(digit == d || digit<=sum)
            {
                return false;
            }
            sum += digit;
        }
        
        return true;
    }
    vector<int> goodNumbers(int L, int R, int D) 
    {
        // code here
        vector<int> ans;
        
        for(int i=L ; i<=R ; i++)
        {
            if(check(i , D))
                ans.push_back(i);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int L, R, D;
        cin >> L >> R >> D;
        Solution ob;
        vector<int> ans = ob.goodNumbers(L, R, D);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}
// } Driver Code Ends