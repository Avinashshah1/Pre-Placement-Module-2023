struct node
{
    int key;
    int val;
    struct node *next;
};

typedef struct node Node;


class MyHashMap {
public:
    Node *head;
    MyHashMap() {
        head = NULL;
    }
    
    void put(int key, int value) {
        if (get(key)!=-1)
        {
            Node *node = getNode(key);
            node->val = value;
            return;
        }
        
        Node *newnode = new Node();
        newnode->key = key;
        newnode->val = value;
        newnode->next = NULL;
        
        if (head == NULL)
        {
            head=newnode;
            return;
        }
        else if (newnode->key < head->key)
        {
            newnode->next = head;
            head = newnode;
            return;
        }
        else
        {
            Node *pre = NULL;
            Node *cur = head;
            
            while(cur && cur->key < newnode->key)
            {
                pre=cur;
                cur=cur->next;
            }
            
            pre->next=newnode;
            newnode->next=cur;
        }
    }
    
    Node* getNode(int key) {
        if (head==NULL)
            return NULL;
        
        Node *cur = head;
        
        while(cur && cur->key<=key)
        {
            if (cur->key==key)
                return cur;
            cur=cur->next;
        }
        return NULL;
    }
    
    int get(int key) {
        if (head==NULL)
            return -1;
        
        Node *cur = head;
        
        while(cur && cur->key<=key)
        {
            if (cur->key==key)
                return cur->val;
            cur=cur->next;
        }
        return -1;
    }
    
    void remove(int key) {
        if(head==NULL)
            return;
        
        if (head->key == key)
        {
            head=head->next;
            return;
        }
        Node *cur, *pre;
        pre=NULL;
        cur = head;
        
        while(cur && cur->key<=key)
        {
            if (cur->key==key)
            {
                pre->next=cur->next;
                return;
            }
            pre=cur;
            cur=cur->next;
        }
        
    }
};