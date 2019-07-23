#include<bits/stdc++.h>
using namespace std;

int N;

void heapify(vector<int> &arr, int i){
    int l = 2*i + 1;
    int r = l + 1;
    int largest = i;
    if(l < N && arr[largest] < arr[l])
        largest = l;
    if(r < N && arr[largest] < arr[r])
        largest = r;
    if(largest !=i ){
        swap(arr[i], arr[largest]);
        heapify(arr, largest);
    }
}

 void getMin(vector<int> &arr){
    int val = arr[0];
    swap(arr[0], arr[N-1]);
    N--;
    cout<<val<<" ";
    heapify(arr, 0);
}

void buildheap(vector<int> &arr){
    for(int i=N/2-1;i>=0;i--)
        heapify(arr, i);
}

int main(){
    int n;
    cin>>n;
    N = n;
    vector<int>arr;
    while(n--){
        int elem;
        cin>>elem;
        arr.push_back(elem);
    }
    buildheap(arr);
    while(N > 0){
        getMin(arr);
    }
    return 0;
}