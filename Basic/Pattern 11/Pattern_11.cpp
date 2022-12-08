//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution 
{
  public:
    void printTriangle(int n) 
    {
        int a = 1;
        
        for(int i=0;i<n;i++)
        {
            int b = a;
            for(int j=0;j<=i;j++)
            {
                cout<<b<<" ";
                if(b==1)
                    b=0;
                else
                    b=1;
            }
            cout<<endl;
            if(a==1)
                a=0;
            else
                a=1;
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
