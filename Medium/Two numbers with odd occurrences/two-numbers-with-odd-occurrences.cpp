//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    vector<long long int> twoOddNum(long long int arr[], long long int N)  
    {
        // code here
        long long int xr = 0;
        for(long long int i = 0; i<N; i++)
            xr = xr^arr[i];
        
        long long int count = 0;
        while(xr != 0)
        {
            if(xr&1 == 1)
                break;
            count++;
            xr = xr>>1;
        }
        
        long long int xr1 = 0, xr2 = 0;
        long long int mask = 1<<count;
        
        for(long long int i = 0; i<N ; i++)
        {
            if(arr[i]&mask)
            {
                xr1 = xr1^arr[i];
            }
            else
            {
                xr2 = xr2^arr[i];
            }
        }
        if(xr1 > xr2)
            return {xr1, xr2};
        else
            return {xr2, xr1};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends