//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution 
{
  public:
    void printTriangle(int n) 
    {
        int k = 2;
        int skip;
        
        for(int i=0;i<=(n*2);i++)
        {
            if(i==n)
                continue;
                
            int count = abs(n - i);
            if(i<n)
                skip = i*2;
            else
            {
                skip = (i - k)*2;
                k=k+2;
            }
            int flag = 0;
            for(int j=0;j<(n*2);j++)
            {
                if(j<count)
                    cout<<"*";
                else
                    cout<<" ";
                if(j>=count)
                    flag++;
                
                if(flag>=skip)
                    count = (n*2);
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
