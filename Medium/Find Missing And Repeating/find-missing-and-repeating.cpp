//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> findTwoElement(vector<int> arr, int n) 
    {
        // code here
        int miss = 0, repeat = 0;
        for(int i=0;i<n;i++)
        {
            if(arr[abs(arr[i]) - 1] < 0)
                repeat = abs(arr[i]);
            else
                arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        }
        for(int i=0;i<n;i++)
        {
            if(arr[i]>0)
            {
                miss = i+1;
                break;
            }
        }
        return {repeat, miss};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends