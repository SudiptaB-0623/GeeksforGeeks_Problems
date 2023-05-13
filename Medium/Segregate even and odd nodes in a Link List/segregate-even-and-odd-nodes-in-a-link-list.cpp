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
        cout << node->data <<" "; 
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
    Node* divide(int N, Node *head)
    {
        // code here
        Node *front = NULL, *back = NULL, *temp = head, *tojoin = NULL;
        if(head->data%2 == 0)
        {
            front = head;
            back = head;
        }
        else
        {
            tojoin = head;
        }
        
        while(temp!=NULL && temp->next!=NULL)
        {
            if(temp->next->data % 2 == 0)
            {
                //cout<<temp->next->data<<endl;
                
                if(tojoin!=NULL)
                {
                    Node *flag = temp->next;
                    temp->next = flag->next;
                    flag->next = tojoin;
                    if(back == NULL)
                    {
                        back = flag;
                        front = back;
                    }
                    else
                    {
                        //cout<<flag->data<<endl;
                        back->next = flag;
                        back = flag;
                    }
                    continue;
                }
                else
                    back = back->next;
            }
            else
            {
                if(tojoin==NULL)
                    tojoin = temp->next;
            }
            temp = temp->next;
        }
        if(front!=NULL)
            return front;
        else
            return head;
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends