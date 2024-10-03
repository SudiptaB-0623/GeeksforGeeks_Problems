//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

void printList(Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
    printf("\n");
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

class Solution 
{
  public:
    Node* merge(Node *left, Node *right)
    {
        Node *start = new Node(-1);
        Node *rear = start;
        Node *t1 = left;
        Node *t2 = right;
        
        while(t1!=NULL && t2!=NULL)
        {
            if(t1->data < t2->data)
            {
                rear->bottom = t1;
                t1 = t1->bottom;
            }
            else
            {
                rear->bottom = t2;
                t2 = t2->bottom;
            }
            rear = rear->bottom;
            rear->next = NULL;
            rear->bottom = NULL;
        }
        if(t1!=NULL)
            rear->bottom = t1;
        if(t2!=NULL)
            rear->bottom = t2;
            
        return start->bottom;
    }
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) 
    {
        // Your code here
        if(root==NULL || root->next==NULL)
            return root;
            
        Node *right = flatten(root->next);
        
        Node *ans = merge(root, right);
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        vector<int> work;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            work.push_back(number);
        }
        n = work.size();

        Node *head = NULL;
        Node *pre = NULL;

        for (int i = 0; i < n; i++) {
            int m = work[i] - 1;
            int data;
            cin >> data;
            Node *temp = new Node(data);
            if (head == NULL) {
                head = temp;
                pre = temp;
            } else {
                pre->next = temp;
                pre = temp;
            }

            Node *preB = temp;
            for (int j = 0; j < m; j++) {
                int temp_data;
                cin >> temp_data;
                Node *tempB = new Node(temp_data);
                preB->bottom = tempB;
                preB = tempB;
            }
        }

        Solution ob;
        Node *root = ob.flatten(head);
        printList(root);
    }
    return 0;
}

// } Driver Code Ends