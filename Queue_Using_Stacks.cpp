#include<bits/stdc++.h>
using namespace std;
class Qu2{
    stack<int> st1, st2;
    public:
    Qu2(){
        st1 = stack<int>();
        st2 = stack<int>();
    }
    void shiftElem(){
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
    }

    void insert(int val){
        //insert into st1
        st1.push(val);
    }
    int pop(){
        //return from s2 and if it is empty move everything from s1 to s2 and then return
        int val = peek();
        st2.pop();
        return val;
    }
    int peek(){
        if(st2.empty()){
            shiftElem();
        }
        int val = st2.top();
        return val;        
    }
};

int main(){
    Qu2 q;
    q.insert(1);
    q.insert(2);
    q.insert(3);
    cout<<q.peek()<<endl;
    cout<<q.peek()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.peek()<<endl;
}