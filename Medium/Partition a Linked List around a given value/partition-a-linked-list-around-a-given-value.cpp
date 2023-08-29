//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node* partition(struct Node* head, int x);

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void) {
    int t;
    cin >> t;

    while (t--) {
        struct Node* head = NULL;
        struct Node* temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;
            if (i == 0) {
                head = new Node(value);
                temp = head;
            } else {
                temp->next = new Node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        // Solution ob;

        head = partition(head, k);
        printList(head);
    }

    return (0);
}

// } Driver Code Ends


// User function Template for C++

/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/

struct Node* partition(struct Node* head, int x) 
{
    // code here
    if(head == NULL)
            return NULL;
        
        Node *small = new Node(-1);
        Node *slast = small;
        Node *big = new Node(-1);
        Node *blast = big;
        Node *equal = new Node(-1);
        Node *elast = equal;
                
        while(head != NULL)
        {
            if(head->data < x)
            {
                slast->next = head;
                head = head->next;
                slast = slast->next;
                slast->next = NULL;
            }
            else if(head->data > x)
            {
                blast->next = head;
                head = head->next;
                blast = blast->next;
                blast->next = NULL;
            }
            else
            {
                elast->next = head;
                head = head->next;
                elast = elast->next;
                elast->next = NULL;
            }
        }
        slast->next = (equal->next == NULL ? big->next : equal->next);
        elast->next = big->next;
        head = small->next;
        
        return head;
}