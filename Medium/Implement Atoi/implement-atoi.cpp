//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    /*You are required to complete this method */
    int atoi(string str) 
    {
        //Your code here
        int sign = 1;
        int n = str.size();
        long long int integer = 0;
        
        for(int i=0 ; i<n ; i++)
        {
            if(i==0 && str[0]=='-')
                sign = -1;
            else if(str[i]>='0' && str[i]<='9')
            {
                integer = (integer*10) + (str[i]-48);
            }
            else
                return -1;
        }
        
        if(sign*integer >= INT_MAX)
            return INT_MAX;
        else if(sign*integer<=INT_MIN)
            return INT_MIN;
        
        return sign*integer;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends