//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
	public:
		string is_palindrome(int n)
		{
		    vector<int> front, back;
		    int num = n;
		    
		    while(num!=0)
		    {
		        front.insert(front.begin(),num%10);
		        back.push_back(num%10);
		        num=num/10;
		    }
		    
		    for(int i=0;i<back.size();i++)
		    {
		        if(front[i]!=back[i])
		            return ("No");
		    }
		    return ("Yes");
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	Solution ob;
    	string ans = ob.is_palindrome(n);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends
