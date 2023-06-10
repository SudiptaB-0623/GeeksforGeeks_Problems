//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) 
	{
	    // code here
	    long long int maxVal = arr[0], minVal = arr[0], maxProduct = arr[0];
	    
	    for(int i=1; i<n ; i++)
	    {
	        if(arr[i]<0)
	        {
	            swap(maxVal, minVal);
	        }
	        
	        if(arr[i] > arr[i]*maxVal)
	            maxVal = arr[i];
	        else
	            maxVal = arr[i]*maxVal;
	        
	        if(arr[i] < arr[i]*minVal)
	            minVal = arr[i];
	        else
	            minVal = arr[i]*minVal;
	            
	        if(maxVal>maxProduct)
	            maxProduct = maxVal;
	        //maxVal = max(maxVal*arr[i] , arr[i]);
	        //minVal = min(minVal*arr[i] , arr[i]);
	        
	        //maxProduct = max(maxVal, maxProduct);
	    }
	    return maxProduct;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends