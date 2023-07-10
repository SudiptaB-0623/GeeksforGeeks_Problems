//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<int> minPartition(int N)
    {
        
        vector<int> coins = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
        int n = coins.size();
        vector<int> ans;
        
        int target = N;
        while(target!=0)
        {
            int i = 0;
            for(; i<n-1 && coins[i+1]<=target; i++);
            
            int freq = target/coins[i];
            while(freq>0)
            {
                ans.push_back(coins[i]);
                freq--;
            }
            target = target%coins[i];
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends