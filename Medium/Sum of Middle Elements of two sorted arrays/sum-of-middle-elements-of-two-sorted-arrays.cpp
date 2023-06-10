//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
public:
    int findMidSum(int ar1[], int ar2[], int n) 
    {
            // code here 
            int sum = 0;
            int i=0, j=0, k=0;
            for(; k<=n && i<n && j<n ;k++)
            {
                int curr;
                if(ar1[i]<ar2[j])
                {
                    curr = ar1[i];
                    i++;
                }
                else
                {
                    curr = ar2[j];
                    j++;
                }
                if(k==n || k==n-1)
                {
                    sum += curr;
                }
            }
            if(k<=n)
            {
                if(i==n)
                {
                    sum += ar2[j];
                }
                else if(j==n)
                {
                    sum += ar1[i];
                }
            }
            return sum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int ar1[n], ar2[n];
        for (i = 0; i < n; i++) {
            cin >> ar1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> ar2[i];
        }
        Solution ob;
        auto ans = ob.findMidSum(ar1, ar2, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends