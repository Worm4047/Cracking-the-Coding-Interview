#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    struct Node *next;
};
typedef struct Node node;

class LinkedList{
    
    public:
    node *head;
    LinkedList(){
        this->head = NULL;
    }
    node * createNode(int val){
        node* temp = (node *)malloc(sizeof(node));
        temp->val = val;
        temp->next = NULL;
        return temp;
    }

    node *addNode(node *head, int val){
        node *temp = createNode(val);
        if(!head)
            return temp;
        node *curr = head;
        while(curr->next)
            curr = curr->next;
        curr->next = temp;
        return head;
    }

    node *removeNode(node *head, int val){
        node *curr = head;
        node *prev = NULL;
        while(curr->val != val){
            prev = curr;
            curr = curr->next;
        }
        //Head node or only node
        if(!prev)
            return head->next;
        prev->next = curr->next;
        return head;
    }
    void displayList(node *head){
        while(head){
            cout<<head->val<<" ";
            head=head->next;
        }
    }
};

class HashMap{
    public:
    int SIZE;
    vector<LinkedList> mp;
    HashMap(int V){
        this->SIZE = V;
        mp = vector<LinkedList>(V, LinkedList());
    }

    void insertKey(int key){
        int idx = key%(this->SIZE);
        node *head = mp[idx].head;
        mp[idx].head = mp[idx].addNode(head, key);
    }

    void removeKey(int key){
        int idx = key%(this->SIZE);
        node *head = mp[idx].head;
        mp[idx].head = mp[idx].removeNode(head, key);
    }

    void displayHash(){
        for(int i=0;i<mp.size();i++){
            cout<<i<<"--->";
            mp[i].displayList(mp[i].head);
            cout<<endl;
        }
    }

};

int main(){
    int a[] = {15, 11, 27, 8, 12}; 
    int n = sizeof(a)/sizeof(a[0]); 

    // insert the keys into the hash table 
    HashMap h(7);   // 7 is count of buckets in 
                // hash table 
    for (int i = 0; i < n; i++)  
    h.insertKey(a[i]);   

    // delete 12 from hash table 
    h.removeKey(12); 

    // display the Hash table 
    h.displayHash(); 

    return 0;
}
