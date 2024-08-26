//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
        if(low>high)
            return;
            
        int pivot = partition(arr, low, high);
        
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       // Your code here
       
       int pivot = arr[low];
       int left = low, right = high;
       
       while(left<right)
       {
            while(left<=high-1 && arr[left]<=pivot)
                left++;
            while(right>=low+1 && arr[right]>pivot)
                right--;
            
            if(left < right)
                swap(arr[left], arr[right]);
       }
       swap(arr[low], arr[right]);
       return right;
    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends