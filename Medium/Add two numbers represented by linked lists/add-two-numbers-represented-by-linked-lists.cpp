//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
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
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        stack<int> s1, s2;
        int carry =0;
        Node *temp = first, *ans=NULL;
        while(temp!=NULL)
        {
            s1.push(temp->data);
            temp = temp->next;
        }
        temp = second;
        while(temp!=NULL)
        {
            s2.push(temp->data);
            temp = temp->next;
        }
        while(!s1.empty() || !s2.empty())
        {
            int val = carry;
            carry = 0;
            if(!s1.empty())
            {
                val += s1.top();
                s1.pop();
            }
            if(!s2.empty())
            {
                val += s2.top();
                s2.pop();
            }
            carry = val/10;
            val = val%10;
            if(ans == NULL)
            {
                ans = new Node(val);
            }
            else
            {
                temp = new Node(val);
                temp->next = ans;
                ans = temp;
            }
        }
        if(carry!=0)
        {
            temp = new Node(carry);
            temp->next = ans;
            ans = temp;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends