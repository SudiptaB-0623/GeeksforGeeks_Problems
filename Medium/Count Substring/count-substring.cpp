//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
  public:
    int countSubstring(string s) 
    {
        // Code here
        int a = 0, b = 0, c = 0;
        int n = s.size();
        int left = 0, right = 0;
        int ans = 0;
        
        while(right<n)
        {
            if(s[right] == 'a')
                a++;
            else if(s[right] == 'b')
                b++;
            else 
                c++;
            
            while(a!=0 && b!=0 && c!=0)
            {
                ans++;
                ans+= n-right-1;
                if(s[left] == 'a')
                    a--;
                else if(s[left] == 'b')
                    b--;
                else 
                    c--;
                left++;
            }
            
            right++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution obj;
        cout << obj.countSubstring(s) << endl;
    }
    return 0;
}
// } Driver Code Ends