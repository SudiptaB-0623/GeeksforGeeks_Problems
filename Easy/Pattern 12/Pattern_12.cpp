//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution 
{
  public:
    void printTriangle(int n) 
    {
        for(int i=1;i<=n;i++)
        {
            int count = 1;
            for(int j=1;j<=(n*2);j++)
            {
                if(count<=i)
                    cout<<count<<" ";
                else
                {
                    cout<<"  ";
                }
                
                if(j<n)
                    count++;
                else if(j>n)
                    count--;
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
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends
