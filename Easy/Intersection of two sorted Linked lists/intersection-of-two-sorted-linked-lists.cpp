//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
}

Node* findIntersection(Node* head1, Node* head2);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Node* result = findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends


/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

Node* findIntersection(Node* head1, Node* head2)
{
    // Your Code Here
    Node *front = NULL, *flag = NULL, *t1 = head1, *t2 = head2;
    
    while(t1!=NULL && t2!=NULL)
    {
        //cout<<t1->data<<" "<<t2->data<<endl;
        if(t1->data > t2->data)
        {
            t2 = t2->next;
        }
        else if(t1->data < t2->data)
        {
            t1 = t1->next;
        }
        else
        {
            Node *temp = new Node(t1->data);
            t1 = t1->next;
            t2 = t2->next;
            if(front == NULL)
            {
                front = temp;
                flag = temp;
                continue;
            }
            flag->next = temp;
            flag = flag->next;
        }
    }
    return front;
}