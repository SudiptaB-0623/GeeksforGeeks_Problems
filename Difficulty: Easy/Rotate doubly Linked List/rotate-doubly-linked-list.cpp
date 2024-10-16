//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
  int data;
  struct node*next,*prev;
  
  node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }
  
} Node;


// } Driver Code Ends
//User function Template for C++

/*
typedef struct node
{
  int data;
  struct node*next,*prev;
  
  node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }
  
} Node;
*/

class Solution 
{
public:
    Node *rotateDLL(Node *start,int p)
    {
        //Add your code here
        Node *rear = start;
        Node *newStart = NULL;
        Node *temp = start;
        
        while(rear->next != NULL)
            rear = rear->next;
            
        for(int i=1; i<p; i++)
            temp = temp->next;
        
        newStart = temp->next;
        temp->next = NULL;
        newStart->prev = NULL;
        rear->next = start;
        start->prev = rear;
        
        return newStart;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,p;
        cin>>n>>p;
        struct node*start = NULL;
        struct node* cur = NULL;
        struct node* ptr = NULL;
        
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            ptr=new node(a);
            ptr->data=a;
            ptr->next=NULL;
            ptr->prev=NULL;
            if(start==NULL)
            {
                start=ptr;
                cur=ptr;
            }
            else
            {
                cur->next=ptr;
                ptr->prev=cur;
                cur=ptr;
            }
        }
        Solution obj;
        struct node*str=obj.rotateDLL(start,p);
        while(1)
        {
            cout<<str->data<<" ";
            if(str->next==NULL)break;
            str=str->next;
        }
        // while(str!=NULL)
        // {
        //     cout<<str->data<<" ";
        //     str=str->prev;
        // }
        cout<< "\n";   
    }
}


// } Driver Code Ends