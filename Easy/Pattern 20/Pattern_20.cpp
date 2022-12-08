//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution 
{
  public:
    void printTriangle(int n) 
    {
        int count = 1;
        
        for(int i=1;i<(n*2);i++)
        {
            int flag = 1;
            
            for(int j=1;j<=(n*2);j++)
            {
                if(flag<=count)
                    cout<<"*";
                else
                    cout<<" ";
                
                if(j<n)
                    flag++;
                else if(j==n)
                    continue;
                else
                    flag--;
            }
            cout<<endl;
            if(i<n)
                count++;
            else
                count--;
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
