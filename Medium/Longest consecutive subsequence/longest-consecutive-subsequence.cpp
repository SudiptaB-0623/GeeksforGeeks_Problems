//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        //Your code here
        set<int> st;
        for(int i=0 ; i<N ; i++)
        {
            st.insert(arr[i]);
        }
        int ans = 1, count = 1;
        int i = 0, prev, curr;
        
        for(auto& it : st)
        {
            if(i==0)
            {
                prev = it;
            }
            else
            {
                curr = it;
                if(curr-prev == 1)
                {
                    count++;
                }
                else
                {
                    count = 1;
                }
                ans = max(ans, count);
                prev = curr;
            }
            i++;
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