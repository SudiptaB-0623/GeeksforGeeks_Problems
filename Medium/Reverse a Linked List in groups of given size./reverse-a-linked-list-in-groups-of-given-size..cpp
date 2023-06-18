//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    node *rev(node *head)
    {
        node *prev = NULL;
        node *nex = NULL;
        node *curr = head;
        while(curr!=NULL)
        {
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return prev;
    }
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        if(head->next == NULL || k == 1)
            return head;
        node *temp = head, *to_join = NULL;
        
        while(temp!=NULL)
        {
            node *first = temp;
            for(int i=1; i<k && temp->next!=NULL;i++)
                temp = temp->next;
            
            node *last = temp;
            temp = temp->next;
            last->next = NULL;
            
            node *flag = rev(first);
            if(first == head)
                head = flag;
            first->next = temp;
            if(to_join == NULL)
            {
                to_join = first;
            }
            else
            {
                to_join->next = flag;
                to_join = first;
            }
        }
        return head;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends