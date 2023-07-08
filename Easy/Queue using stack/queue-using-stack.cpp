//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Queue 
{
    stack<int> input, output;
public:

    void enqueue(int x) 
    {
        input.push(x);
    }

    int dequeue() 
    {
        if(output.empty())
        {
            while(input.empty() != true)
            {
                output.push(input.top());
                input.pop();
            }
        }
        if(output.empty())
            return -1;
        
        int top = output.top();
        output.pop();
        
        return top;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Queue ob;

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            ob.enqueue(a);
        }
        else if(QueryType==2)
        {
            cout<<ob.dequeue()<<" ";

        }
        }
    cout<<endl;
    }
}

// } Driver Code Ends