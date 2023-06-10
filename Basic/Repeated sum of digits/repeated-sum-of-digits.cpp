//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
public:
    int repeatedSumOfDigits(int N)
    {
        // code here 
        int num = N;
        while(num/10!=0)
        {
            int n = num, sum = 0;
            while(n != 0)
            {
                sum += n%10;
                n /= 10;
            }
            num = sum;
        }
        return num;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.repeatedSumOfDigits(N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends