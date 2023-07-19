//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    private:

    public:
    //Constructor for initializing the cache capacity with the given value.
    class node
    {
      public:
        int key;
        int val;
        node *next;
        node *prev;
        node(int key_, int val_)
        {
            key = key_;
            val = val_;
            next = NULL;
            prev = NULL;
        }
    };
    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);
    
    int cap;
    unordered_map<int, node*> mpp;
    LRUCache(int cap_)
    {
        // code here
        cap = cap_;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(node *temp)
    {
        temp->next = head->next;
        temp->prev = head;
        head->next = temp;
        (temp->next)->prev = temp;
    }
    void deleteNode(node *temp)
    {
        (temp->prev)->next = temp->next;
        (temp->next)->prev = temp->prev;
    }
    
    //Function to return value corresponding to the key.
    int GET(int key_)
    {
        // your code here
        if(mpp.find(key_) != mpp.end())
        {
            node* temp = mpp[key_];
            int data = temp->val;
            
            mpp.erase(key_);
            deleteNode(temp);
            
            addNode(temp);
            mpp[key_] = head->next;
            
            return data;
        }
        return -1;
    }
    
    //Function for storing key-value pair.
    void SET(int key_, int value)
    {
        // your code here  
        if(mpp.find(key_) != mpp.end())
        {
            node *temp = mpp[key_];
            mpp.erase(key_);
            deleteNode(temp);
        }
        if(cap == mpp.size())
        {
            node *temp = tail->prev;
            int todel = temp->key;
            mpp.erase(todel);
            deleteNode(temp);
        }
        
        node *temp = new node(key_, value);
        addNode(temp);
        mpp[key_] = head->next;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends