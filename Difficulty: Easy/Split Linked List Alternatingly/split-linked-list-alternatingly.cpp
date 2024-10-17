//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
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
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) 
    {
        // Your code here
        Node *start1 = new Node(-1);
        Node *rear1 = start1;
        Node *start2 = new Node(-1);
        Node *rear2 = start2;
        
        int i=1;
        Node *temp = head;
        while(temp != NULL)
        {
            if(i%2 == 1)
            {
                rear1->next = temp;
                rear1 = temp;
                temp = temp->next;
                rear1->next = NULL;
            }
            else
            {
                rear2->next = temp;
                rear2 = temp;
                temp = temp->next;
                rear2->next = NULL;
            }
            i++;
        }
        
        return {start1->next, start2->next};
    }
};


//{ Driver Code Starts.

void printList(struct Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        struct Node* head = new Node(arr[0]);
        struct Node* tail = head;

        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        vector<Node*> result = ob.alternatingSplitList(head);
        printList(result[0]);
        printList(result[1]);
    }

    return 0;
}

// } Driver Code Ends