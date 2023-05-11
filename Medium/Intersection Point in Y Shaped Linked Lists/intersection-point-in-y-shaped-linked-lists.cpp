//{ Driver Code Starts
#include<iostream>

#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}


// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    int l1 = 0, l2 = 0;
    Node *trav1 = head1, *trav2 = head2, *temp = head1;
    while(temp!=NULL)
    {
        l1++;
        temp = temp->next;
    }
    temp = head2;
    while(temp!=NULL)
    {
        l2++;
        temp = temp->next;
    }
    int diff = abs(l1-l2);
    if(l1>l2)
    {
        temp = head1;
        while(diff>0)
        {
            temp = temp->next;
            diff--;
        }
        trav1 = temp;
    }
    else
    {
        temp = head2;
        while(diff>0)
        {
            temp = temp->next;
            diff--;
        }
        trav2 = temp;
    }
    while(trav1!=NULL)
    {
        if(trav1 == trav2)
            return trav1->data;
        
        trav1 = trav1->next;
        trav2 = trav2->next;
    }
    return -1;
}

