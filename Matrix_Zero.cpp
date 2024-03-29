#include<bits/stdc++.h>
using namespace std;

void makeZero(vector<vector<int>> &arr){

    int n = arr.size();
    int m = arr[0].size();
    bool row = false, col = false;
    for(int i=0;i<m;i++){
        if(arr[0][i] == 0){
            row = true;
            break;
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i][0] == 0){
            col = true;
            break;
        }
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(arr[i][j] == 0){
                arr[i][0] = 0;
                arr[0][j] = 0;
            }
        }
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(arr[i][0] * arr[0][j] == 0)
                arr[i][j] = 0;
        }
    }

    if(row){
        for(int i=0;i<m;i++)
            arr[0][i] = 0;
    }

    if(col){
        for(int i=0;i<n;i++)
            arr[i][0] = 0;
    }


}

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> arr(n, vector<int>(m, 0));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>arr[i][j];
    makeZero(arr);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
}