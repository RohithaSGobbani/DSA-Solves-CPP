#include<bits/stdc++.h>
using namespace std;

//Brute
int missing(vector<int> &arr, int k){
    int n = arr.size();
    for(int i = 0; i < n; i++){
        if(arr[i] < k) k++;
        else break;
    }
    return k;
}

int main(){
    int n;
    cin >> n; 
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int k;
    cin >> k;
    cout << missing(arr, k);
}