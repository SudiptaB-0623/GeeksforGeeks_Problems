//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution 
{
  public:
    bool checkSorted(vector<int> &arr) 
    {
        // code here.
        int n = arr.size();
        int count = 0;
        bool flag = true;
        
        for(int i=0; i<n; i++)
        {
            int pos = i;
            while(arr[pos] != i+1)
            {
                pos++;
            }
            if(pos != i)
            {
                flag = false;
                count++;
                swap(arr[pos], arr[i]);
            }
            if(count>2)
                return false;
        }
        
        if(flag)
            return true;
        
        return (count==2);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        bool ans = ob.checkSorted(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}

// } Driver Code Ends