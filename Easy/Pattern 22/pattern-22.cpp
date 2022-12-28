//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution 
{
  public:
    void printSquare(int n) 
    {
        // code here
        for(int i=1;i<=2*n-1;i++)
        {
            int k=n;
            if(i<=n)
            {
                for(int j=1;j<=2*n-1;j++)
                {
                    cout<<k<<" ";
                    if(i>1 && i>j)
                    {
                        k=k-1;
                    }
                    else if(i>1 && (i+j)>=2*n)
                    {
                        k=k+1;
                    }  
                }
            }
            else
            {
                for(int j=1;j<=2*n-1;j++)
                {
                    cout<<k<<" ";
                    if((i+j)<2*n && i<2*n-1)
                    {
                        k=k-1;
                    }
                    else if(j>=i && i<2*n-1)
                    {
                        k=k+1;
                    }
                }
            }
            cout<<endl;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        ob.printSquare(n);
    }
    return 0;
}
// } Driver Code Ends