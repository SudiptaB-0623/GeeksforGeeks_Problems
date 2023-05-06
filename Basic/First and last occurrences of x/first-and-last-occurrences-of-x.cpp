//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    // code here
    vector<int> ans = {-1, -1};
    for(int l = 0, r = n-1;l<=r;)
    {
        if(arr[l]==x && ans[0]==-1)
            ans[0]=l;
        else
        {
            if(ans[0]==-1)
                l++;
        }
        if(arr[r]==x && ans[1]==-1)
            ans[1]=r;
        else
        {
            if(ans[1]==-1)
                r--;
        }
        if(ans[0]!=-1 && ans[1]!=-1)
            break;
    }
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