//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution
{
    int minEle;
    stack<int> s;
    public:
    
    /*returns min element from stack*/
    int getMin()
    {
        //Write your code here
        if(s.empty())
            return -1;
        return minEle;
    }
       
    /*returns poped element from stack*/
    int pop()
    {
        //Write your code here
        if(s.empty())
            return -1;
            
        int t = s.top();
        if(t<minEle)
        {
            int temp = minEle;
            minEle = (2*minEle) - t;
            t = temp;
        }
        s.pop();
        
        return t;
    }
       
    /*push element x into the stack*/
    void push(int x)
    {
       //Write your code here
       int temp = x;
        if(s.empty())
            minEle = x;
        else
        {
            if(temp<minEle)
            {
                temp = (2*x)-minEle;
                minEle = x;
            }
        }
        s.push(temp);
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends