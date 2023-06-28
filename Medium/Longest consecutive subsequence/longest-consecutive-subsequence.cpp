//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        //Your code here
        sort(arr, arr+N);
        int ans = 1, len = 0;
        int curr;
        
        for(int i=0; i<N ; i++)
        {
            if(i>0 && arr[i]==arr[i-1])
                continue;
            
            if(i==0)
            {
                curr = arr[0];
                len = 1;
                continue;
            }
            
            if(arr[i] == curr+1)
            {
                curr++;
                len++;
                ans = max(ans, len);
            }
            else
            {
                curr = arr[i];
                len = 1;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends