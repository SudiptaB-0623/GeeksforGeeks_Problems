//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution 
{
  public:
    int totalFruits(int N, vector<int> &fruits) 
    {
        int ans = 0;
        int left = 0, right = 0;
        vector<int> fruit(2, -1);
        vector<int> freq(2, 0);
        
        while(right<N)
        {
            if(freq[0] == 0 || fruits[right]==fruit[0])
            {
                freq[0]++;
                fruit[0] = fruits[right];
            }
            else if(freq[1] == 0 || fruits[right]==fruit[1])
            {
                freq[1]++;
                fruit[1] = fruits[right];
            }
            else if(fruits[right]!=fruit[0] && fruits[right]!=fruit[1])
            {
                while(freq[0]!=0 && freq[1]!=0)
                {
                    if(fruits[left]==fruit[0])
                        freq[0]--;
                    else
                        freq[1]--;
                    
                    left++;
                }
                
                if(freq[0]==0)
                {
                    freq[0]=1;
                    fruit[0]=fruits[right];
                }
                else
                {
                    freq[1] = 1;
                    fruit[1]=fruits[right];
                }
            }
            ans = max(ans, right-left+1);
            //cout<<fruits[right]<<" "<<ans<<endl;
            right++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends