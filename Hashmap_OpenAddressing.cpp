#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    int val;
    Node() : key(-1), val(-1) {
    }
};
typedef struct Node node;

class HashMap{
    int capacity;
    vector<node> mp;
    public:
    HashMap(int s){
        capacity = s;
        mp = vector<node>(s, node());
    }

    int hashFunction(int key){
        return key % capacity;
    }

    void insertVal(int key, int val){
        int idx = hashFunction(key);
        while(mp[idx].key != -1 && mp[idx].key != key){
            idx++;
            idx = idx % capacity;
        }
        mp[idx].key = key;
        mp[idx].val = val;
    }

    void deleteKey(int key, int val){
        int idx = hashFunction(key);
        while(mp[idx].key != -1){
            if(mp[idx].key == key){
                mp[idx].key = -1;
                return;
            }
            idx++;
            idx = idx % capacity;
        }
    }

    void display(){
        for(int i=0;i<mp.size();i++){
            cout<<i<<" "<<mp[i].key<<" "<<mp[i].val<<endl;
        }
    }

};

int main(){
    HashMap h(3); 
    h.insertVal(1,1); 
    h.insertVal(2,2); 
    h.insertVal(3,3); 
    h.display(); 
    h.deleteKey(2, 2);
    h.insertVal(4,4);
    h.display();
    return 0;     
}