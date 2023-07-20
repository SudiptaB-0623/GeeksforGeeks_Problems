//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int n)
    {
        // your code here
        string ans = "";
        
        for(int i=0; i<arr[0].size() ; i++)
        {
            bool check = true;
            for(int j=1 ; j<n ; j++)
            {
                if(i>=arr[j].size() || arr[j][i]!=arr[0][i])
                {
                    check = false;
                    break;
                }
            }
            
            if(check == false)
                break;
            else
                ans = ans+arr[0][i];
        }
        if(ans.size()==0)
            return "-1";
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends