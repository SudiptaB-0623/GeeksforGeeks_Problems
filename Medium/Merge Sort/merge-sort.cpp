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
    void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         //Creating two arrays m1, m2 of size a, b respectively to store the elements of each half in it

        int a = m-l+1;
        int b = r-m;
    
        int m1[a], m2[b];
    
        for(int i=0;i<a;i++)
        {
            m1[i]=arr[l+i];
        }
        for(int i=0;i<b;i++)
        {
            m2[i]=arr[m+1+i];
        }
    
        //Comparing the arrays m1, m2 and merging them in sorted order
    
        for(int i=0,j=0,k=0;(i<a)||(j<b);)
        {
            if(i>=a)                            //if m1 runs out of element, just keep adding elements from m2
            {            
                arr[l+k]=m2[j];
                j++;
                k++;
                continue;
            }
            if(j>=b)                            //if m2 runs out of element, just keep adding elements from m1
            {
                arr[l+k]=m1[i];
                i++;
                k++;
                continue;
            }
    
            //Compare and merge elements accordingly
    
            if(m1[i]<m2[j])
            {
                arr[l+k]=m1[i];
                i++;
            }
            else
            {
                arr[l+k]=m2[j];
                j++;
            }
            k++;
        }
    }
    public:
    void mergeSort(int arr[], int left, int right)
    {
        //code here
        if(left<right)                              
        {                                           
            int mid = (left+right)/2;
    
            mergeSort(arr,left,mid);                //Left half of the broken array part
            mergeSort(arr,mid+1,right);             //Right half of the broken array part
            merge(arr,left,mid,right);              //Merging the broken halfs in sorted order
        }
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends