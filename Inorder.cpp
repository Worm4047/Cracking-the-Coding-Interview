#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    struct Node *left;
    struct Node *right;
};

typedef struct Node node;
node *createnode(int val){
    node *temp = (node *)malloc(sizeof(node));
    temp->val=val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void inorder(node *root){
    if(!root) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

void preorder(node *root){
    if(!root) return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder2(node *root){
    node *curr = root;
    stack<node *> st;
    while(1){
        while(curr){
            st.push(curr);
            curr = curr->left;
        }
        if(st.empty())
            break;
        curr = st.top();
        st.pop();
        cout<<curr->val<<" ";
        curr = curr->right;
    }
}

void preorder2(node *root){
    node *curr = root;
    stack<node *> st;
    st.push(curr);
    while(!st.empty()){
        node *temp = st.top();
        cout<<temp->val<<" ";
        st.pop();
        if(temp->right)
            st.push(temp->right);
        if(temp->left)
            st.push(temp->left);
    }
}

int main(){
    node *root = NULL;
    root = createnode(5);
    root->left = createnode(1);
    root->left->left = createnode(3);
    root->left->right = createnode(6);
    root->right = createnode(7);
    inorder(root);
    cout<<endl;
    inorder2(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    preorder2(root);
}
