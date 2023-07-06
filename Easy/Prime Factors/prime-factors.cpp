//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
	public:

	vector<int> AllPrimeFactors(int N) 
	{
	    // Code here
	    vector<int> sieve(N+1, 1);
	    sieve[0] = sieve[1] = 0;
	    
	    for(int i=2 ; i<sieve.size() ; i++)
	    {
	        if(sieve[i] == 0)
	            continue;
            for(int j = 2; i*j<sieve.size() ; j++)
                sieve[i*j] = 0;
	    }
	    
	    vector<int> ans;
	    for(int i=1; i<sieve.size(); i++)
	    {
	        if(N%i==0 && sieve[i] == 1)
	            ans.push_back(i);
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.AllPrimeFactors(N);
		for(auto i: ans)
			cout << i <<" ";
		cout <<"\n";
	}  
	return 0;
}
// } Driver Code Ends