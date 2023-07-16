//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
    
    int maxProfit(vector<int>&prices)
    {
        //Write your code here..
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        
        for(int ind=n-1 ; ind>=0 ; ind--)
        {
            for(int buy=0 ; buy<=1 ; buy++)
            {
                for(int cap=1 ; cap<=2 ; cap++)
                {
                    int profit = 0;
                    if(buy == 1)
                    {
                        int take = -prices[ind] + dp[ind+1][0][cap];
                        int notTake = dp[ind+1][1][cap];
                        
                        profit = max(take, notTake);
                    }
                    else
                    {
                        int sell = prices[ind] + dp[ind+1][1][cap-1];
                        int notSell = dp[ind+1][0][cap];
                        
                        profit = max(sell, notSell);
                    }
                    
                    dp[ind][buy][cap] = profit;
                }
            }
        }
        
        return dp[0][1][2];
    }

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends