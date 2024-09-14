//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    void backtrack(int digits[], int index, const unordered_map<int, string>& mpp, 
        string& currentCombination, vector<string>& result, int N) 
    {
        if (index == N) 
        {
            result.push_back(currentCombination);
            return;
        }
        
        int digit = digits[index];
        string letters = mpp.at(digit);
        for (char letter : letters) 
        {
            currentCombination.push_back(letter);
            backtrack(digits, index + 1, mpp, currentCombination, result, N);
            currentCombination.pop_back(); // Backtrack by removing the last letter added
        }
    }
    
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        vector<string> result;
        
        unordered_map<int, string> mpp = 
        {
            {2, "abc"},
            {3, "def"},
            {4, "ghi"},
            {5, "jkl"},
            {6, "mno"},
            {7, "pqrs"},
            {8, "tuv"},
            {9, "wxyz"}
        };
        
        string currentCombination;
        backtrack(a, 0, mpp, currentCombination, result, N);
        
        return result;
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends