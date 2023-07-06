//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    vector<int> sieveOfEratosthenes(int N)
    {
        // Write Your Code here
        vector<int> sieve(N+1, 1);
        sieve[0] = sieve[1] = 0;
        for(int i=2;i<sieve.size();i++)
        {
            if(sieve[i] == 0)
                continue;
            for(int j=2; i*j<sieve.size();j++)
                sieve[i*j] = 0;
        }
        
        vector<int> prime;
        for(int i=1; i<=N ; i++)
        {
            if(sieve[i] == 1)
                prime.push_back(i);
        }
        return prime;
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
        Solution ob;
        vector<int> primes  = ob.sieveOfEratosthenes(N);
        for(auto prime : primes) {
            cout<< prime <<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends