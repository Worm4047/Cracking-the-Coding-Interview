#include<bits/stdc++.h>
using namespace std;

void insert(stack<int> &st, int val){
    stack<int> temp;
    while(!st.empty() && st.top() < val){
        temp.push(st.top());
        st.pop();
    }
    st.push(val);
    while(!temp.empty()){
        st.push(temp.top());
        temp.pop();
    }
}

void display(stack<int> st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}

int main(){
    stack<int> st;
    int n;
    cin>>n;
    while(n--){
        int elem;
        cin>>elem;
        insert(st, elem);
    }
    display(st);
    return 0;
}