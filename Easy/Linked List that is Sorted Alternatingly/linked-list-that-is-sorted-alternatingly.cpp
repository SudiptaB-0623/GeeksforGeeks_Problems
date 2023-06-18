//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};

void sort(Node **head);


void append(struct Node** headRef, struct Node** tailRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    *tailRef = *headRef;
	    return;
	}
	
	(*tailRef) -> next = new_node;
	*tailRef = (*tailRef) -> next;
}

// A utility function to print a linked list
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	int test;
	cin>>test;
	while(test--)
	{
	    struct Node* head = NULL;
	    struct Node* tail = NULL;
	    int n, k;
	    cin>>n;
	    for(int i=0; i<n ;i++){
	        cin>>k;
	        append(&head, &tail, k);
	    }
	    sort(&head);
	    printList(head);
	}
	return 0;
}

// } Driver Code Ends


/*Structure of Node of the linked list is as
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/
// your task is to complete this function
Node *rev(Node *head)
{
    Node *prev = NULL, *nex = NULL, *curr = head;
    while(curr!=NULL)
    {
        nex = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nex;
    }
    
    return prev;
}
Node* merge(Node* head1, Node* head2)  
{  
    // code here
    Node *first = new Node(-1);
    Node *last = first;
    
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->data < head2->data)
        {
            last->next = head1;
            head1 = head1->next;
        }
        else
        {
            last->next = head2;
            head2 = head2->next;
        }
        last = last->next;
        last->next = NULL;
    }
    if(head1!=NULL)
        last->next = head1;
    if(head2!=NULL)
        last->next = head2;
    
    last = first;
    first = first->next;
    delete last;
    return first;
} 
void sort(Node **head)
{
    // Code here
    if((*head)->next == NULL || ((*head)->next->next==NULL))
        return;
    
    Node *odd = new Node(-1);
    Node *even = new Node(-1);
    Node *o = odd, *e = even;
    
    Node *temp = *head;
    for(int i=1;temp!=NULL;i++)
    {
        if(i%2==1)
        {
            o->next = temp;
            temp = temp->next;
            o = o->next;
            o->next = NULL;
        }
        else
        {
            e->next = temp;
            temp = temp->next;
            e = e->next;
            e->next = NULL;
        }
    }
    
    odd = odd->next;
    even = even->next;
    even = rev(even);
    *head = merge(odd, even);
    
}