//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution 
{
  public:
    void bitManipulation(int num, int i) 
    {
        // your code here
        int get = ((num & (1<<(i-1)))!=0);
        int set = num | (1<<(i-1));
        int clc = num & (~(1<<(i-1)));
        
        cout<<get<<" "<<set<<" "<<clc;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;
        Solution ob;
        ob.bitManipulation(n, i);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends