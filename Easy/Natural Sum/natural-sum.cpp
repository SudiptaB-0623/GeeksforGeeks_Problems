//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
	public:
   	int find(int n)
   	{
   	    // Code here
   	    int sum = 0;
   	    for(int i=1; sum<=n ; i++)
   	    {
   	        sum += i;
   	        if(sum == n)
   	            return i;
   	    }
   	    return -1;
   	}    
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.find(n);
		cout << ans <<"\n";
	}  
	return 0;
}
// } Driver Code Ends