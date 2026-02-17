#include<bits/stdc++.h>
using namespace std;

void getRow(int rowIndex) {
    vector<int> ansV;
    long long ans = 1;
    ansV.push_back(ans);
    for(int i = 1; i < rowIndex+1; i++){
        ans = ans * (rowIndex+1 - i);
        ans = ans / i;
        ansV.push_back(ans);
    }
    for(auto a: ansV){
        cout << a << " ";
    }
}


int main(){
    int n; 
    cin >> n;
    getRow(n);
}