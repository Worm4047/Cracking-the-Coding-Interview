#include<bits/stdc++.h>
using namespace std;

string compString(string str){
    int n = str.length();
    string res = "";
    for(int i=0;i<n;i++){
        int count = 1;
        res += str[i];
        while(i<n-1 && str[i] == str[i+1]){
            count++;
            i++;
        }
        res += to_string(count);
    }
    return res;
}

int main(){
    string str = "geeksforgeeks";
    cout<<compString(str);
    return 0;
}