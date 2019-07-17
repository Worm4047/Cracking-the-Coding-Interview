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

node *inputList(){
    int n;
    cin>>n;
    node *head1 = NULL;
    for(int i=0;i<n;i++){
        int elem;
        cin>>elem;
        head1 = insertNode(head1, elem);
    }
    return head1;
}

void display(node *head){
    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}

node *sumList(node* head1, node* head2){
    node *curr1 = head1, *curr2 = head2;
    node *res = NULL;
    int c = 0;
    while(curr1 && curr2){
        int s = curr1->val + curr2->val + c;
        c = s/10;
        s = s%10;
        res = insertNode(res, s);
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    while(curr1){
        int s = curr1->val + c;
        c = s/10;
        s = s%10;
        res = insertNode(res, s);
        curr1 = curr1->next;
    }
    while(curr2){
        int s = curr2->val + c;
        c = s/10;
        s = s%10;
        res = insertNode(res, s);
        curr2 = curr2->next;
    }
    if(c){
        res = insertNode(res, c);
    }    
    return res;
}

int main(){
    int n, m;
    
    node *head1 = inputList();
    node *head2 = inputList();

    display(head1);
    display(head2);
    node *head3 = sumList(head1, head2);
    display(head3);    
}