//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution 
{
  public:
    int pairsum(vector<int> &arr) 
    {
        // code here
        int l1 = -1;
        int l2 = -2;
        int ans = 0;
        
        for(auto num : arr)
        {
            if(num > l1)
            {
                l2 = l1;
                l1 = num;
            }
            else if(num > l2)
                l2 = num;
        }
        
        return l1+l2;
    }
};


//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int r = ob.pairsum(arr);
        cout << r << endl;
    }
    return 0;
}
// } Driver Code Ends