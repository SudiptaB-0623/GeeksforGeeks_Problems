//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void sub_seq(vector<int> a, vector<int> b, vector<int> &ans)
    {
        int sum = 0;
        for(int i=0;i<a.size();i++)
            sum += a[i];
        ans.push_back(sum);
        
        if(b.size()==0)
            return;
        
        for(int i=0;i<b.size();i++)
        {
            vector<int> temp, temp2;
            temp2.insert(temp2.end(), a.begin(), a.end());
            temp2.insert(temp2.end(), b.begin()+i, b.begin()+i+1);
            
            temp.insert(temp.begin(), b.begin()+i+1, b.end());
            sub_seq(temp2, temp, ans);
        }
    }
    vector<int> subsetSums(vector<int> nums, int N)
    {
        // Write Your Code here
        vector<int> ans;
        
        for(int i=0;i<N;i++)
        {
            vector<int> temp , temp2;
            temp.insert(temp.begin(), nums.begin()+i+1,nums.end());
            temp2.push_back(nums[i]);
            
            sub_seq(temp2, temp, ans);
        }
        ans.push_back(0);
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
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends