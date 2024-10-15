//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }

    int data = arr[0];
    Node* head = new Node(data);
    Node* tail = head;
    for (int i = 1; i < arr.size(); ++i) {
        data = arr[i];
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/*
// structure of the node is as follows

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
class Solution {
  public:
  Node *middle(Node *head)
    {
        Node *slow = head;
        Node *fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    Node *merge(Node *head1, Node *head2)
    {
        if(head1==NULL)
            return head2;
        if(head2 == NULL)
            return head1;
        Node *first = new Node(-1);
        Node *last = first;
        
        while(head1!=NULL && head2!=NULL)
        {
            if(head1->data < head2->data)
            {
                last->next = head1;
                head1 = head1->next;
            }
            else
            {
                last->next = head2;
                head2 = head2->next;
            }
            last = last->next;
            last->next = NULL;
        }
        if(head1!=NULL)
            last->next = head1;
        if(head2!=NULL)
            last->next = head2;
        
        last = first;
        first = first->next;
        delete last;
        return first;
    }
    Node* mergeSort(Node* head) 
    {
        // your code here
        if(head == NULL || head->next == NULL)
            return head;
        
        Node *mid = middle(head);
        
        Node *left = head;
        Node *right = mid->next;
        mid->next = NULL;
        
        left = mergeSort(left);
        right = mergeSort(right);
        
        Node *ans = merge(left, right);
        return ans;
    }
    struct Node* makeUnion(struct Node* head1, struct Node* head2) 
    {
        // code here
        Node *temp = head1;
        while(temp->next != NULL)
            temp = temp->next;
        
        temp->next = head2;
        
        Node *ans = mergeSort(head1);
        
        temp = ans;
        while(temp!=NULL && temp->next!=NULL)
        {
            if(temp->data == temp->next->data)
                temp->next = temp->next->next;
            else
                temp=temp->next;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        Node* first = buildList();

        Node* second = buildList();
        Solution obj;
        Node* head = obj.makeUnion(first, second);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends