//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        unordered_map<int, int> mpp;
        int sum = 0;
        int ans = 0;
       
        for(int i=0; i<N; i++)
        {
            sum += A[i];
            if(sum == K)
                ans = max(ans, i+1);
            auto it = mpp.find(sum);
            if(it == mpp.end())
                mpp[sum] = i;
            auto it2 = mpp.find(sum-K);
            if(it2 != mpp.end())
            {
                //cout<<"here"<<mpp[sum-K]<<endl;
                ans = max(ans, i - mpp[sum-K] );
            }
        }
       
        return ans;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends