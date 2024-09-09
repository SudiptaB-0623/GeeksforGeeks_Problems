//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    void binary(int ind, vector<string> &ans, string temp, int num)
    {
        if(temp.size() == num)
        {
            ans.push_back(temp);
            return;
        }
        
        temp = temp + "0";
        binary(ind+1, ans, temp, num);
        temp.erase(temp.size()-1);
        if(temp.size()==0 || (temp.size()>0 && temp[temp.size()-1]!='1'))
        {
            temp = temp + '1';
            binary(ind+1, ans, temp, num);
        }
    }
    
    vector<string> generateBinaryStrings(int num)
    {
        //Write your code
        vector<string> ans;
        string temp;
        
        binary(0, ans, temp, num);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        
        vector<string> v = obj.generateBinaryStrings(n);
        for(auto it:v) cout<<it<<" ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends