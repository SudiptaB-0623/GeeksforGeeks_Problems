//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution 
{
  public:
    // vector<int> s(2*10e5, 1);
    void sieve()
    {
        // s[0] = s[1] = 0;
        // for(int i=2; i*i<=n ; i++)
        // {
        //     if(s[i] == 0)
        //         continue;
        //     for(int j=2; i*j<=n ;j++)
        //         s[j] = 0;
        // }
    }

    vector<int> findPrimeFactors(int N) 
    {
        // Write your code here
        vector<int> s(N+1, 1);
        //sieve();
        
        s[0] = s[1] = 0;
        for(int i=2; i*i<=N ; i++)
        {
            if(s[i] == 0)
                continue;
            for(int j=2; i*j<=N ;j++)
                s[i*j] = 0;
        }
        
        vector<int> prime, ans;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == 1)
            {
                prime.push_back(i);
            }
        }
        
        int n = N;
        while(n!=1)
        {
            for(int i=0;i<prime.size();i++)
            {
                if(n%prime[i] == 0)
                {
                    ans.push_back(prime[i]);
                    n = n/prime[i];
                    break;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n;
        cin >> n;

        Solution obj;
        obj.sieve();
        vector<int> vec = obj.findPrimeFactors(n);
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends