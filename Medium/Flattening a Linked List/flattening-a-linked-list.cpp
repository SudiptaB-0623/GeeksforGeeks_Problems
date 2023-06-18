//{ Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}

// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
Node *merge(Node *left, Node *right)
{
    if(left==NULL)
        return right;
    Node *temp = left;
    while(temp!=NULL)
    {
        temp->next = temp->bottom;
        temp->bottom = NULL;
        temp = temp->next;
    }
    
    if(right==NULL)
        return left;
    temp = right->next;
    right->next = NULL;
    right = merge(right, temp);
    
    Node *first = new Node(-1);
    Node *last = first;
    while(left!=NULL && right!=NULL)
    {
        if(left->data<right->data)
        {
            last->next = left;
            left = left->next;
        }
        else
        {
            last->next = right;
            right = right->next;
        }
        last=last->next;
        last->next = NULL;
    }
    
    if(left!=NULL)
        last->next = left;
    if(right!=NULL)
        last->next = right;
    
    first = first->next;
    
    return first;
}
Node *flatten(Node *root)
{
   // Your code here
    if(root == NULL)
        return root;
    Node *left = root, *right = root->next;;
    left->next = NULL;
   
    Node *ans = merge(left, right); 
    Node *temp = ans;
    while(temp!=NULL)
    {
        temp->bottom = temp->next;
        temp->next = NULL;
        temp = temp->bottom;
    }
    
    return ans;
}

