//{ Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool palindrome(int i, string& s)
	{
    
        // Base Condition
        // If i exceeds half of the string means all the elements 
        // are compared, we return true.
        if(i>=s.length()/2) return true;
        
        // If the start is not equal to the end, not the palindrome.
        if(s[i]!=s[s.length()-i-1]) return false;
        
        // If both characters are the same, increment i and check start+1 and end-1.
        return palindrome(i+1,s);
    }
	
	int isPalindrome(string S)
	{
	    // Your code goes here
	    return palindrome(0, S);
	}

};

//{ Driver Code Starts.

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPalindrome(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends