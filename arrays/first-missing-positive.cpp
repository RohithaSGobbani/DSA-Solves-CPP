#include<bits/stdc++.h>
using namespace std;

//Brute
int firstMissingPositive(vector<int>& arr) {
    int n = arr.size();
    if(n==1){
        if(arr[0] == 1) return 2;
        else return 1;
    }
    unordered_map<int,int> mpp;
    for(int i = 0; i < n; i++){
        mpp[arr[i]]++;
    }
    int mini = INT_MAX;
    for(int i = 1; i < n+2; i++){
        if(mpp[i] == 0){
            mini = min(mini, i);
        }
    }
    return mini;
}

/*
Input: nums = [1,2,0]
Output: 3
*/

int main(){
    int n;
    cin >> n; 
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout<< firstMissingPositive(arr);
}
