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
        if(head->next == NULL)
            return head;
        Node *first = head, *last = head;
       
        while(last->next!=NULL)
            last = last->next;
        int i=1;
        for(; i<=N && (first->data%2)==1;i++)
        {
            Node *temp = first;
            first = first->next;
            temp->next = NULL;
            last->next = temp;
            last = temp;
        }
        i++;
        Node *temp = first;
        for(; i<=N ; i++)
        {
            if(temp->next->data%2 == 1)
            {
                Node *flag = temp->next;
                if(flag==last)
                    continue;
                temp->next = flag->next;
                flag->next = NULL;
                last->next = flag;
                last = flag;
            }
            else
                temp = temp->next;
        }
        return first;
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