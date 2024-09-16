//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string kthPermutation(int n, int k)
    {
        // code here
        string ans = "";
        vector<int> nums;
        int temp = k-1;
        int fact = 1;
        
        for(int i=1; i<n; i++)
        {
            nums.push_back(i);
            fact = fact*i;
        }
        nums.push_back(n);
        
        while(true)
        {
            int ind = temp/fact;
            ans = ans + to_string(nums[ind]);
            nums.erase(nums.begin() + ind);
            
            if(nums.size()==0)
                break;
                
            temp = temp%fact;
            fact = fact/nums.size();
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends