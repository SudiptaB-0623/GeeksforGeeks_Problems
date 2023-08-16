//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution 
{
  public:
    int romanToDecimal(string &str) 
    {
        // code here
        int integer = 0;
        int n = str.size();
        
        map<char, int> mpp;
        mpp['I'] = 1;
        mpp['V'] = 5;
        mpp['X'] = 10;
        mpp['L'] = 50;
        mpp['C'] = 100;
        mpp['D'] = 500;
        mpp['M'] = 1000;
        
        for(int i=0 ; i<n ; i++)
        {
            if(i+1 == n || mpp[str[i]] >= mpp[str[i+1]])
                integer += mpp[str[i]];
            else
                integer -= mpp[str[i]];
        }
        
        return integer;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends