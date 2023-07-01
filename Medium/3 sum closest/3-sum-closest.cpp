//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    int closest3Sum(int A[], int N, int X)
    {
        // code here
        int sum = 0;
        int minDiff = INT_MAX;
        
        sort(A, A+N);
        
        for(int i=0 ; i<N ; i++)
        {
            if(i>0 && A[i] == A[i-1])
                continue;
            int low = i+1;
            int high = N-1;
            while(low<high)
            {
                int currSum = A[i]+A[low]+A[high];
                if(currSum == X)
                    return currSum;
                else if(abs(X-currSum) < minDiff)
                {
                    minDiff = abs(X-currSum);
                    sum = currSum;
                }
                
                if(currSum < X)
                {
                    low++;
                    while(low<high && A[low] == A[low-1])
                        low++;
                }
                else 
                {
                    high--;
                    while(low<high && A[high] == A[high+1])
                        high--;
                }
                
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int X;
        cin>>X;
        Solution obj;
        cout<<obj.closest3Sum(Arr, N, X)<<endl;
    }
    return 0;
}
// } Driver Code Ends