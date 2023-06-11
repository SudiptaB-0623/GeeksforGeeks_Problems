//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        // Your code goes here  
        int mm = -1, sum = 0;
        int low = 0, high = 0;
        
        while(high<n)
        {
            sum += arr[high];
            if(sum > x)
            {
                if(mm == -1)
                {
                    mm = (high - low) + 1;
                }
                else 
                    mm = min(mm, (high - low) + 1);
                
                while((sum - arr[low]) > x)
                {
                    sum -= arr[low];
                    low++;
                    mm = min(mm, (high - low) + 1);
                }
            }
            //cout<<mm<<" "<<high<<" "<<low<<" "<<sum<<endl;
            if(sum>x && mm == 1)
                return mm;
            high++;
        }
        return mm;
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends