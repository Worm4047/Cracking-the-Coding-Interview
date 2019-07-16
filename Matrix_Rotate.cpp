#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>> &arr){
    int n = arr.size();
    int lo = 0, hi = n-1;
    while(lo < hi){
        for(int i=0;i<hi-lo;i++){
            int temp = arr[lo][i+lo];
            arr[lo][i+lo] = arr[hi-i][lo];
            arr[hi-i][lo] = arr[hi][hi-i];
            arr[hi][hi-i] = arr[i+lo][hi];
            arr[i+lo][hi] = temp;
        }
        lo++;
        hi--;
    }
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> arr(n, vector<int>(n, 0));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    
    rotate(arr);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}