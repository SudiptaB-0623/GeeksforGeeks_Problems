//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x)
        : data(x)
        , next(nullptr) {}
};

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data;
        head = head->next;
    }
    cout << '\n';
}


// } Driver Code Ends
// User function Template for C++

class Solution 
{
  public:
    int findSize(Node *head)
    {
        int size = 0;
        Node *temp = head;
        while(temp!=NULL)
        {
            size++;
            temp = temp->next;
        }
        return size;
    }
    Node *findLargerNum(Node* head1, Node* head2)
    {
        int size1 = findSize(head1);
        int size2 = findSize(head2);
        
        if(size1 == size2)
        {
            Node *temp1 = head1;
            Node *temp2 = head2;
            while(temp1!=NULL && temp1->data == temp2->data)
            {
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            if(temp1==NULL)
                return NULL;
            return (temp1->data>temp2->data) ? head1 : head2;
        }
        
        return (size1>size2) ? head1 : head2;
    }
    Node *reverse(Node *head)
    {
        Node *prev = NULL, *next = NULL;
        Node *curr = head;
        
        while(curr!=NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    Node* subLinkedList(Node* head1, Node* head2) 
    {
        // Your implementation of subLinkedList goes here
        // Make sure to return the head of the resulting linked list
        Node *num1 = findLargerNum(head1, head2);
        if(num1 == NULL)
        {
            Node *ans = new Node(0);
            return ans;
        }
        Node *num2 = (num1 == head1) ? head2 : head1;
        Node *ans = new Node(-1);
        Node *rear = ans;
        
        num1 = reverse(num1);
        num2 = reverse(num2);
        
        Node *temp1 = num1;
        Node *temp2 = num2;
        int carry = 0;
        while(temp2 != NULL)
        {
            int a = temp1->data;
            int b = temp2->data + carry;
            carry = 0;
            if(a<b)
            {
                a+=10;
                carry = 1;
            }
            int diff = a-b;
            rear->next = new Node(diff);
            rear = rear->next;
            
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        while(temp1 != NULL)
        {
            int a = temp1->data;
            int b = carry;
            carry = 0;
            if(a<b)
            {
                a+=10;
                carry = 1;
            }
            rear->next = new Node(a-b);
            temp1 = temp1->next;
            rear = rear->next;
        }
        ans = reverse(ans->next);
        while(ans->next!=NULL && ans->data == 0)
            ans = ans->next;
        return ans;
    }
};

//{ Driver Code Starts.

// Driver program to test the above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        Node *head1 = nullptr, *tail1 = nullptr;
        Node *head2 = nullptr, *tail2 = nullptr;
        string input1, input2;

        cin >> input1 >> input2;
        for (char ch : input1) {
            int tmp = ch - '0';
            Node* new_node = new Node(tmp);
            if (!head1) {
                head1 = new_node;
                tail1 = new_node;
            } else {
                tail1->next = new_node;
                tail1 = new_node;
            }
        }

        for (char ch : input2) {
            int tmp = ch - '0';
            Node* new_node = new Node(tmp);
            if (!head2) {
                head2 = new_node;
                tail2 = new_node;
            } else {
                tail2->next = new_node;
                tail2 = new_node;
            }
        }

        Solution obj;
        Node* result = obj.subLinkedList(head1, head2);
        printList(result);
    }
    return 0;
}

// } Driver Code Ends