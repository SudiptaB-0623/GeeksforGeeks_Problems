//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

// } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution
{
  public:
    //Function to merge K sorted linked list.
    Node *merge(Node *head1, Node *head2)
    {
        Node *temp = head1, *flag = head2;
        Node *outp = new Node(-1);
        Node *last = outp;
        
        // Node *a = head1;
        // while(a!=NULL)
        // {
        //     cout<<a->data<<" ";
        //     a = a->next;
        // }
        // cout<<endl;
        
        while(temp!=NULL && flag!=NULL)
        {
            if(temp->data < flag->data)
            {
                Node *t = new Node(temp->data);
                temp = temp->next;
                last->next = t;
                last = last->next;
            }
            else
            {
                Node *t = new Node(flag->data);
                flag = flag->next;
                last->next = t;
                last = last->next;
            }
        }
        if(temp!=NULL)
        {
            while(temp!=NULL)
            {
                Node *t = new Node(temp->data);
                temp = temp->next;
                last->next = t;
                last = last->next;
            }
        }
        if(flag!=NULL)
        {
            while(flag!=NULL)
            {
                Node *t = new Node(flag->data);
                flag = flag->next;
                last->next = t;
                last = last->next;
            }
        }
        flag = outp;
        outp = outp->next;
        delete flag;
        return outp;
    }
    Node * mergeKLists(Node *arr[], int K)
    {
        // Your code here
        // if(K==1)
        //     return arr[0];
        
        // Node *output = merge(arr[0], arr[1]);
        
        // for(int i=2; i<K ; i++)
        // {
        //     output = merge(output, arr[i]);
        // }
        // return output;
        priority_queue<int,vector<int>,greater<int>> pq;
           for(int i=0;i<K;i++){
               Node *curr=arr[i];
               while(curr!=NULL){
                   pq.push(curr->data);
                   curr=curr->next;
               }
           }
           int n=pq.size();
           Node *root=new Node(0);
           Node *curr=root;
           for(int i=0;i<n;i++){
               Node *temp=new Node(pq.top());
               curr->next=temp;
               pq.pop();
               curr=curr->next;
           }
           return root->next;
    }
};



//{ Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}

// } Driver Code Ends