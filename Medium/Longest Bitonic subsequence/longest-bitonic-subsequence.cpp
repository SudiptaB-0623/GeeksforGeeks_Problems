//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    int n = nums.size();
	    vector<int> left(n, 1), right(n, 1);
	    
	    for(int i=0; i<n ; i++)
	    {
	        for(int j=0; j<i ; j++)
	        {
	            if(nums[j]<nums[i] && left[j]+1>left[i])
	                left[i] = left[j]+1;
	        }
	    }
	    for(int i=n-1; i>=0 ; i--)
	    {
	        for(int j=n-1; j>i ; j--)
	        {
	            if(nums[j]<nums[i] && right[j]+1>right[i])
	                right[i] = right[j]+1;
	        }
	    }
	    int maxi = -1;
	    for(int i=0 ; i<n ; i++)
	    {
	        maxi = max(maxi, left[i]+right[i]-1);
	    }
	    return maxi;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends