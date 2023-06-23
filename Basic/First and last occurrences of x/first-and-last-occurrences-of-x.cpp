//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    // code here
    vector<int> ans;
    int curr = INT_MAX;
    
    int low = 0, high = n-1;
    while(low<=high)
    {
        int mid = (high + low)/2;
        if(arr[mid] == x)
        {
            curr = min(curr, mid);
            high = mid - 1;
        }
        else if(arr[mid] > x)
            high = mid - 1;
        else
            low = mid + 1;
    }
    
    if(curr == INT_MAX)
        ans.push_back(-1);
    else
        ans.push_back(curr);
    curr = INT_MIN;
    
    low = 0;
    high = n-1;
    while(low<=high)
    {
        int mid = (high + low)/2;
        if(arr[mid] == x)
        {
            curr = max(curr, mid);
            low = mid + 1;
        }
        else if(arr[mid] > x)
            high = mid - 1;
        else
            low = mid + 1;
    }
    if(curr == INT_MIN)
        ans.push_back(-1);
    else
        ans.push_back(curr);
    return ans;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends