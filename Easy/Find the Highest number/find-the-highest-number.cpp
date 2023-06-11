//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
public:
    int findPeakElement(vector<int>& a) 
    {
        // Code here.
        int low = 0, high = a.size()-1, ans = 0;
        while(low<=high)
        {
            int mid = (high+low);
            if(a[mid]>a[mid-1])
            {
                ans = max(ans, a[mid]);
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	vector<int>a(n);
    	for(int i = 0; i < n; i++)
    		cin>>a[i];
    	Solution ob;
    	int ans = ob.findPeakElement(a);
    	cout << ans << "\n";
    }
	return 0;
}


// } Driver Code Ends