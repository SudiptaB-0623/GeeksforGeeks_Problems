//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the smallest window in the string s1 consisting
    // of all the characters of string s2.
    string smallestWindow(string &s1, string &s2) 
    {
        // Your code here
        int n = s1.size();
        int m = s2.size();
        
        if(m>n) 
            return "-1";
            
        int arr[26] = {0};
        for(int i=0; i<m; i++)
           arr[s2[i]-'a']++;
          
        int i = 0, j = 0;
        int count = m;
        int ans = INT_MAX;
        int ind = 0;
        
        while(j<n && i<n)
        {
            if(arr[s1[j]-'a'] > 0) 
                count--;
            arr[s1[j]-'a']--;
            
            while(count==0 && i<n)
            {
                if(ans>(j-i+1))
                {
                    ind= i;
                    ans = (j-i+1);
                }
                arr[s1[i]-'a']++;
                if(arr[s1[i]-'a']>0) 
                    count++;
                i++;
            }
            j++;
        }
        
        if(ans==INT_MAX) 
            return "-1";
            
        return s1.substr(ind, ans);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1;
        cin >> s1;
        string s2;
        cin >> s2;
        Solution obj;
        cout << obj.smallestWindow(s1, s2) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends