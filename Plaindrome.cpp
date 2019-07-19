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

int getLength(node *head){
    int len = 0;
    while(head){
        len++;
        head = head->next;
    }
    return len;
}

void display(node *head){
    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
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

bool checkPal(node *head){
    int len = getLength(head);
    if(len < 2)
        return true;
    node *p1 = head, *p2 = head, *prev = NULL;
    while(p1 && p2 && p2->next){
        prev = p1;
        p1 = p1->next;
        p2 = p2->next->next;
    }
    if(len %2 == 1)
        p1->next = reverse(p1->next);
    else
        prev->next = reverse(p1);
    p2 = len % 2 == 1 ? p1->next : prev->next;
    p1 = head;
    display(head);
    while(p1 && p2){
        if(p1->val != p2->val)
            return false;
        p1 = p1->next;
        p2 = p2->next;
    }
    return true;
}

bool _recur(node* head, node* &end, int len){
    if(len == 0){
        end = head;
        return true;
    }
    else if(len == 1){
        end = head->next;
        return true;
    }

    bool res = _recur(head->next, end, len-2);
    if(!res || head->val != end->val)
        return false;
    end = end->next;
    return true;
}

bool checkPal2(node *head){
    node *end = NULL;
    int len = getLength(head);
    return _recur(head, end, len);
}

int main(){
    node *head = inputList();
    display(head);
    // cout<<checkPal(head)<<endl;
    cout<<checkPal2(head);
}