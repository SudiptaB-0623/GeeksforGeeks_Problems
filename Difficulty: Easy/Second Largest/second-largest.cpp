//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution 
{
  public:
    // Function returns the second
    // largest elements
    int print2largest(vector<int> &arr) 
    {
        // Code Here
        int first, second;
        if(arr[0] > arr[1])
        {
            first = arr[0];
            second = arr[1];
        }
        else if(arr[1] > arr[0])
        {
            first = arr[1];
            second = arr[0];
        }
        else
        {
            first = arr[0];
            second = -1;
        }
        
        for(int i=2; i<arr.size(); i++)
        {
            if(arr[i]==first || arr[i]==second)
                continue;
            if(arr[i]>first)
            {
                second = first;
                first = arr[i];
            }
            else if(arr[i]>second)
            {
                second = arr[i];
            }
        }
        
        return second;
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
        Solution ob;
        int ans = ob.print2largest(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends