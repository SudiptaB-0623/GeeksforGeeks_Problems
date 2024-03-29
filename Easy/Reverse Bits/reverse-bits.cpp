//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
  public:
    long long reversedBits(long long X) 
    {
        long long ans = 0;
        int index = 31;
        
        while(X!=0)
        {
            if(X%2==1)
            {
                ans += pow(2,index);
                //cout<<ans<<endl;
            }
            index--;
            X=X/2;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends