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

void display(node *head){
    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}

node *rearrange(node *head, int x){
    node *curr_begin = NULL, *curr_end = NULL;
    while(head){
        node *temp = createNode(head->val);
        if(!curr_begin){
            curr_begin = temp;
            curr_end = curr_begin;
        }
        else{
            if(head ->val < x){
                temp->next = curr_begin;
                curr_begin = temp;
            }
            else{
                curr_end->next = temp;
                curr_end = curr_end->next;
            }
        }
        head = head->next;
    }
    return curr_begin;
}



int main(){
    int n, x;
    cin>>n>>x;
    node *head = NULL;
    for(int i=0;i<n;i++){
        int elem;
        cin>>elem;
        head = insertNode(head, elem);
    }
    display(head);
    head = rearrange(head, x);
    display(head);
}