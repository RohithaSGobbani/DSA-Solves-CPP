#include<bits/stdc++.h>
using namespace std;

void sumarray(int i, vector<int> &arr, int n, int sum, vector<int> &ans){
    if(i == n){
        ans.push_back(sum);
        return;
    }
    sum += arr[i];
    
    sumarray(i+1, arr, n, sum , ans);
    sum -= arr[i];
    
    sumarray(i+1, arr, n, sum , ans);
}

vector<int> subsetSums(vector<int>& arr) {
    //your code goes here
    vector<int> ans;
    
    sumarray(0, arr, arr.size(), 0, ans);
    return ans;
}

int main(){
    vector<int> arr = {5,2,1};
    vector<int> ans = subsetSums(arr);
    for(auto a:ans){
        cout << a << " ";
    }
    return 0;
}