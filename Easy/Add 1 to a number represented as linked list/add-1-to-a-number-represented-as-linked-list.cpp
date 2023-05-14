//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* rev(Node *head)
    {
        Node *temp = head, *curr = head, *point = NULL;
        while(temp!=NULL)
        {
            temp = temp->next;
            curr->next = point;
            point = curr;
            curr = temp;
        }
        return point;
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        
        Node *rfront = rev(head);
        
        rfront->data += 1;
        int carry = rfront->data/10;
        rfront->data = rfront->data%10;
        
        Node *temp = rfront;
        
        while(carry!=0)
        {
            if(temp->next == NULL)
            {
                Node *flag = new Node(carry);
                temp->next = flag;
                break;
            }
            temp = temp->next;
            temp->data += 1;
            carry = temp->data/10;
            temp->data = temp->data%10;
        }
        rfront = rev(rfront);
        return rfront;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends