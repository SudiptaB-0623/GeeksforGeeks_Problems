//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << '\n';
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution 
{
  public:
  
    Node *reverse(Node *head)
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *next = NULL;
        
        while(curr!=NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }

    struct Node *mergeResult(Node *node1, Node *node2) 
    {
        // your code goes here
        Node *start = new Node(-1);
        Node *rear = start;
        Node *temp1 = node1;
        Node *temp2 = node2;
        
        while(temp1!=NULL && temp2!=NULL)
        {
            if(temp1->data < temp2->data)
            {
                rear->next = temp1;
                temp1 = temp1->next;
            }
            else
            {
                rear->next = temp2;
                temp2 = temp2->next;
            }
            rear = rear->next;
            rear->next = NULL;
        }
        
        if(temp1!=NULL)
            rear->next = temp1;
        if(temp2!=NULL)
            rear->next = temp2;
            
        Node *head = start->next;
        start->next = NULL;
        delete start;
        
        head = reverse(head);
        
        return head;
    }
};


//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n1, n2, tmp;
        Node *head1 = nullptr, *tail1 = nullptr;
        Node *head2 = nullptr, *tail2 = nullptr;
        string input1, input2;

        getline(cin, input1); // Read the entire line for LL1 elements
        stringstream ss1(input1);
        while (ss1 >> tmp) {
            Node *new_node = new Node(tmp);
            if (head1 == nullptr) {
                head1 = new_node;
                tail1 = new_node;
            } else {
                tail1->next = new_node;
                tail1 = new_node;
            }
        }

        getline(cin, input2); // Read the entire line for LL2 elements
        stringstream ss2(input2);
        while (ss2 >> tmp) {
            Node *new_node = new Node(tmp);
            if (head2 == nullptr) {
                head2 = new_node;
                tail2 = new_node;
            } else {
                tail2->next = new_node;
                tail2 = new_node;
            }
        }

        Solution obj;
        Node *result = obj.mergeResult(head1, head2);

        printList(result);
        // cout << endl;
    }
    return 0;
}

// } Driver Code Ends