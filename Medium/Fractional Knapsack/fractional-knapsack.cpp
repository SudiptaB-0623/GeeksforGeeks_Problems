//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<double,int>> vect;
        double ans = 0;
        
        for(int i=0;i<n;i++)
        {
            pair<double,int> p;
            p.second = i;
            p.first = double(arr[i].value)/double(arr[i].weight);
            vect.push_back(p);
        }
        sort(vect.rbegin(),vect.rend());
        
        for(int i=0;(i<n)&&(W>0);i++)
        {
            int flag = vect[i].second;
            if(arr[flag].weight>W)
            {
                ans += W*(vect[i].first);
                W=0;
            }
            else
            {
                ans += arr[flag].value;
                W -= arr[flag].weight;
            }
            //cout<<ans<<endl;
        }
        return ans;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends