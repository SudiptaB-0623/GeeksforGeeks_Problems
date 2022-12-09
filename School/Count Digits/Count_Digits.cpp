//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int evenlyDivides(int N)
    {
        int count = 0;
        int cpy = N;
        
        while(cpy!=0)
        {
            int den = cpy%10;
            
            if(den!=0)
                if(N%den==0)
                    count++;
            
            cpy = cpy/10;
        }
        return count;
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
        cin>>N;
        Solution ob;
        cout << ob.evenlyDivides(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends
