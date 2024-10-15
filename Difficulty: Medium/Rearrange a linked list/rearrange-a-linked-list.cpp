//{ Driver Code Starts
// Initial Template for C++
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

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
/* Node structure

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
    void rearrangeEvenOdd(Node *head) 
    {
        // Your Code here
        Node *odd = new Node(-1);
        Node *oddRear = odd;
        Node *even = new Node(-1);
        Node *evenRear = even;
        
        int i=1;
        Node *temp = head;
        
        while(temp!=NULL)
        {
            if(i%2 == 1)
            {
                oddRear->next = temp;
                temp = temp->next;
                oddRear = oddRear->next;
                oddRear->next = NULL;
            }
            else
            {
                evenRear->next = temp;
                temp = temp->next;
                evenRear = evenRear->next;
                evenRear->next = NULL;
            }
            i++;
        }
        
        oddRear->next = even->next;
        head = odd->next;
    }
};


//{ Driver Code Starts.

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

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }
        Node *head = nullptr;
        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node *tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        Solution ob;
        ob.rearrangeEvenOdd(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends