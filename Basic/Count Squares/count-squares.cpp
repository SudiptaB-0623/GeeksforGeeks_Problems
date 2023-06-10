//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
  public:
    int countSquares(int N) 
    {
        // code here
        int count = 0;
        //cout<<sqrt(N);
        for(int i=1; i<= sqrt(N);i++)
        {
            if(pow(i,2)<N)
                count++;
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.countSquares(N) << endl;
    }
    return 0;
}
// } Driver Code Ends