//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// long long int maxSum(int arr[], int n);

// } Driver Code Ends
class Solution 
{
  public:
    long long maxSum(vector<int>& arr) 
    {
        // code here
        sort(arr.begin(), arr.end());
        vector<int> temp(arr.size(), 0);
        
        for(int i=0, j=arr.size()-1, l=0; l<arr.size(); l++)
        {
            if(l%2==0)
            {
                temp[l] = arr[i];
                i++;
            }
            else
            {
                temp[l] = arr[j];
                j--;
            }
        }
        
        long long ans = 0;
        for(int i=0; i<arr.size()-1; i++)
        {
            ans += abs(temp[i]-temp[i+1]);
        }
        
        ans += abs(temp[temp.size()-1] - temp[0]);
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        long long ans = ob.maxSum(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends