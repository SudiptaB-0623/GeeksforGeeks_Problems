//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void ins(stack<int> &s , int t)
    {
        if(s.size()==0)
        {
            s.push(t);
        }
        else
        {
            int temp = s.top();
            s.pop();
            ins(s, t);
            
            s.push(temp);
        }
    }
    void Reverse(stack<int> &s)
    {
        if(s.size()==0)
            return;
            
        int t = s.top();
        s.pop();
        
        Reverse(s);
        
        ins(s , t);
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends