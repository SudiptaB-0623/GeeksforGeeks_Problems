//{ Driver Code Starts
#include <iostream>
#include <cstdio>
using namespace std;
 
/* a node of the singly linked list */
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
};

/* A utility function to insert a node at the beginning of linked list */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node = new node(new_data);
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* A utility function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
void quickSort(struct node **headRef);
int main()
{
	int t,n,x;
	cin>>t;
	while(t--){
		
        
        cin>>n;n=n-1;
		cin>>x;
        node *temp,*head = new node(x);
        temp=head;
        while(n--)
        {
			cin>>x;
          temp->next=new node(x);
          temp=temp->next;
			}
    
    quickSort(&head);
 
    printList(head);
 while(head!= NULL){
     temp=head;
     head=head->next;
     free(temp);
     
 }
	}
    return 0;
}
// } Driver Code Ends


 
/* a node of the singly linked list 
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
}; */

//you have to complete this function
node *quick(node *head)
{
    
    if(head == NULL || head->next==NULL)
        return head;
    //cout<<"hello "<<head->data<<endl;
    node *temp = head->next;
    head->next = NULL;
    node *left = new node(-1);
    node *right = new node(-1);
    node *l = left, *r = right;         // l & r are last node pointers of left & right respectively.
    
    while(temp!=NULL)
    {
        if(temp->data < head->data)
        {
            l->next = temp;
            l = temp;
            temp = temp->next;
            l->next = NULL;
        }
        else
        {
            r->next = temp;
            r = temp;
            temp = temp->next;
            r->next = NULL;
        }
    }
    left = left->next;
    right = right->next;
    left = quick(left);
    right = quick(right);
    
    if(left!=NULL)
    {
        temp = left;
        while(temp!=NULL && temp->next!=NULL)
            temp = temp->next;
        temp->next = head;
    }
    else 
        left = head;
    head->next = right;
    //cout<<"returning "<<left->data<<endl;
    return left;
}
void quickSort(struct node **head) 
{
    node *first = *head;
    first = quick(first);
    *head = first;
}