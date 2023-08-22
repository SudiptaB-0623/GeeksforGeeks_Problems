//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution 
{
  public:
    bool feasible(int weights[], int count, int days, int n) 
    {
        int daysReq = 1, curr = 0;
        for(int i=0 ; i<n ; i++) 
        {
            curr += weights[i];
            if (curr > count) 
            {
                daysReq++;
                curr = weights[i];
            }
        }

        return daysReq <= days;
    }
    int leastWeightCapacity(int weights[], int N, int days) 
    {
        // code here
        int total = 0, maxi = 0;
        for(int i=0 ; i<N ; i++) 
        {
            total += weights[i];
            maxi = max(maxi, weights[i]);
        }

        int left = maxi, right = total;

        while(left < right) 
        {
            int mid = (left + right) / 2;
            
            if(feasible(weights, mid, days, N))
                right = mid;
            else 
                left = mid + 1;
        }
        return left;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends