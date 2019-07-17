#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    struct Node *next;
};
typedef struct Node node;
node* createNode(int val){
    node *temp = (node *)malloc(sizeof(node));
    temp->val = val;
    temp->next = NULL;
    return temp;
}

node *insertNode(node *head, int val){
    node *temp = createNode(val);
    if(!head)
        return temp;
    node *curr = head;
    while(curr->next)
        curr = curr->next;
    curr->next = temp;
    return head;
}

node *reverse(node *head){
    node *prev = NULL;
    node *curr = head;
    while(curr){
        node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

void display(node *head){
    while(head){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

node *removeDups(node *head){
    map<int, int> mp;
    node *curr = head, *prev = NULL;
    while(curr){
        if(mp.find(curr->val) == mp.end()){
            mp[curr->val] = 1;
           if(prev)
               prev->next = curr;
            prev = curr;
            curr = curr->next;
            prev->next = NULL;  
        }
        else
            curr = curr->next;
        
    }
    return head;
}

node *removeDups2(node *head){
    node *curr = head;
    while(curr){
        node *curr2 = curr->next;
        node *prev = curr;
        prev->next = NULL;
        while(curr2){
            if(curr2->val == curr->val)
                curr2 = curr2->next;
            else{
                prev->next = curr2;
                prev = curr2;
                curr2 = curr2->next;
                prev->next = NULL;
            }
        }
        curr = curr->next;
    }
    return head;
}

int main(){
    int n;
    cin>>n;
    node *head = NULL;
    for(int i=0;i<n;i++){
        int elem;
        cin>>elem;
        head = insertNode(head, elem);
    }
    display(head);
    head = removeDups2(head);
    display(head);
    return 0;
}
