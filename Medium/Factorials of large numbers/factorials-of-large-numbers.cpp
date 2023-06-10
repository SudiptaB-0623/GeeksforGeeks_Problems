//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
public:
    vector<int> factorial(int N)
    {
        // code here
        vector<int> ans = {1};
        int carry = 0;
        for(int i=2 ; i <= N ; i++)
        {
            for(int j=0 ; j<ans.size() ;j++)
            {
                int mul = ans[j]*i + carry;
                ans[j] = mul%10;
                carry = mul/10;
            }
            
            while(carry!=0)
            {
                ans.push_back(carry%10);
                carry = carry/10;
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends