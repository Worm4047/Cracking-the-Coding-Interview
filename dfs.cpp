#include<bits/stdc++.h>
using namespace std;

void _recur(vector<vector<int>> adj, vector<bool> &visited, int curr){
    visited[curr] = true;
    cout<<curr<<" ";
    for(int i=0;i<adj[curr].size();i++){
        int j = adj[curr][i];
        if(!visited[j])
            _recur(adj, visited, j);
    }
}

void dfsi(vector<vector<int>> adj, vector<bool> &visited, int curr){
    stack<int> st;
    st.push(curr);
    while(!st.empty()){
        int j = st.top();
        st.pop();
        if(!visited[j])
            cout<<"Popped "<<j<<endl;
        visited[j] = true;
        for(int k = 0;k<adj[j].size();k++){
            int l = adj[j][k];
            if(!visited[l]){
                st.push(l);
                // cout<<"Pushed "<<l<<endl;
            }
                
        }
    }
}

void dfs(vector<vector<int>> adj){
    int n = adj.size();
    vector<bool> visited(n, false);
    for(int i=0;i<n;i++){
        if(!visited[i])
            // _recur(adj, visited, i);
            dfsi(adj, visited, i);
    }
}

int main(){
    int n, e;
    cin>>n>>e;
    vector<vector<int>> adj(n, vector<int>());
    for(int i=0;i<e;i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    dfs(adj);
}