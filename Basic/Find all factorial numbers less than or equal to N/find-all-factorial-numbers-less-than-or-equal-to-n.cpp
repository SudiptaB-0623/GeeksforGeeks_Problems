//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    void fact(vector<long long> &ans, long i, long long n)
    {
        if(i*ans[ans.size()-1]<=n)
        {
            ans.push_back(i*ans[ans.size()-1]);
            fact(ans,i+1,n);
        }
    }

    vector<long long> factorialNumbers(long long N)
    {
        // Write Your Code here
        vector<long long> ans = {1};
        
        fact(ans,2,N);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long N;
        cin>>N;
        Solution ob;
        vector<long long> ans = ob.factorialNumbers(N);
        for(auto num : ans){
            cout<<num<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}
// } Driver Code Ends