//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution 
{
  public:
    int sumSubarrayMins(int n, vector<int> &arr) 
    {
        // code here
        int mod = 1e9 + 7;
        stack<int> st;
        vector<int> left(n), right(n);
        
        for(int i=0 ; i<n ; i++)
        {
            if(st.empty() == true)
            {
                left[i] = -1;
                st.push(i);
            }
            else
            {
                while(st.empty()!=true && arr[st.top()]>arr[i])  // greater than is used to avoid duplicate elements.
                    st.pop();
                if(st.empty())
                    left[i] = -1;
                else
                    left[i] = st.top();
                st.push(i);
            }
        }
        
        stack<int> st2;
        for(int i=n-1 ; i>=0 ; i--)
        {
            if(st2.empty() == true)
            {
                right[i] = -1;
                st2.push(i);
            }
            else
            {
                while(st2.empty()!=true && arr[st2.top()]>=arr[i])    // onse side should be greater and other as greater than equal to.
                    st2.pop();
                
                if(st2.empty())
                    right[i] = -1;
                else
                    right[i] = st2.top();
                st2.push(i);
            }
        }
        
        long long int ans = 0;
        for(int i=0 ; i<n ; i++)
        {
            long long int l = (left[i] == -1) ? i+1 : i-left[i];
            long long int r = (right[i] == -1) ? n-i : right[i]-i;
            
            ans = (ans + (l*r)*arr[i])%mod;
        }
        
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

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        cout << obj.sumSubarrayMins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends