//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};


// } Driver Code Ends
//User function Template for C++

/*Link list node 
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    Node *reverse(Node *head)
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *next = NULL;
        
        while(curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    Node* reverseBetween(Node* head, int m, int n)
    {
        //code here
        Node *start = new Node(-1);
        start->next = head;
        
        Node *first, *to_join;
        int count = 0;
        Node *temp = start;
        
        while(temp != NULL)
        {
            count++;
            if(count == m)
            {
                first = temp;
            }
            else if(count == n+1)
            {
                to_join = temp->next;
                temp->next = NULL;
                break;
            }
            temp = temp->next;
        }
        
        Node *new_first = reverse(first->next);
        first->next->next = to_join;
        first->next = new_first;
        
        return start->next;
    }
};

//{ Driver Code Starts.

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}



// Driver program to test above functions
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, m, n;
		cin >> N>>m>>n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		

        Solution ob;

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";



	}
	return 0;
}

// } Driver Code Ends