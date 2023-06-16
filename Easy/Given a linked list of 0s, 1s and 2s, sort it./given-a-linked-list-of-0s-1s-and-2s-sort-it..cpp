//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
// class Solution
// {
//     public:
//     //Function to sort a linked list of 0s, 1s and 2s.
//     Node* segregate(Node *head) 
//     {
//         // Add code here
//         if(head->next == NULL)
//             return head;
            
//         Node *l0 = NULL, *l1 = NULL, *l2 = NULL;
//         Node *l0_last = NULL, *l1_last = NULL, *l2_last = NULL;
        
//         Node *curr = head;
//         head = NULL;
//         while(curr!=NULL)
//         {
//             if(curr->data == 0)
//             {
//                 if(l0 == NULL)
//                 {
//                     l0 = curr;
//                     l0_last = l0;
//                 }
//                 else
//                 {
//                     l0_last->next = curr;
//                     l0_last = l0_last->next;
//                 }
//                 curr = curr->next;
//                 l0_last->next = NULL;
//             }
//             if(curr->data == 1)
//             {
//                 if(l1 == NULL)
//                 {
//                     l1 = curr;
//                     l1_last = l1;
//                 }
//                 else
//                 {
//                     l1_last->next = curr;
//                     l1_last = l1_last->next;
//                 }
//                 curr = curr->next;
//                 l1_last->next = NULL;
//             }
//             if(curr->data == 2)
//             {
//                 if(l2 == NULL)
//                 {
//                     l2 = curr;
//                     l2_last = l2;
//                 }
//                 else
//                 {
//                     l2_last->next = curr;
//                     l2_last = l2_last->next;
//                 }
//                 curr = curr->next;
//                 l2_last->next = NULL;
//             }
//         }
        
//         if(l0!=NULL)
//         {
//             head = l0;
//             l0_last->next = l1;
//         }
//         if(l1!=NULL)
//         {
//             if(head == NULL)
//                 head = l1;
//             l1_last->next = l2;
//         }
        
        
//         if(head == NULL)
//             head = l2;
//         head = l0;
        
//         return head;
//     }
// };
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(struct Node *head) {
    if (!head || !(head->next))
        return head;
  
    //creating three dummy nodes to point to beginning of three linked lists. 
    Node* zeroD = new Node(0); 
    Node* oneD = new Node(0); 
    Node* twoD = new Node(0); 
  
    //initializing current pointers for three lists. 
    Node* zero = zeroD, *one = oneD, *two = twoD; 
  
    //traversing over the list with a pointer. 
    Node* curr = head; 
    while (curr) { 
        
        //we check data at current node and store the node in it's respective
        //list and update the link part of that list.
        if (curr->data == 0) { 
            zero->next = curr; 
            zero = zero->next; 
            curr = curr->next; 
        }
        else if (curr->data == 1) { 
            one->next = curr; 
            one = one->next; 
            curr = curr->next; 
        } 
        else { 
            two->next = curr; 
            two = two->next; 
            curr = curr->next; 
        } 
    } 
  
    //attaching the three lists containing 0s,1s and 2s respectively.
    zero->next = (oneD->next) ? (oneD->next) : (twoD->next); 
    one->next = twoD->next; 
    two->next = NULL; 
  
    //updating the head of the list.
    head = zeroD->next; 
  
    //deleting dummy nodes.
    delete zeroD; 
    delete oneD; 
    delete twoD; 
  
    return head;
}

};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends