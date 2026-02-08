#include<bits/stdc++.h>
using namespace std;

void smallerNumbersThanCurrent(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n);
    for(int i = 0; i < n; i++){
        int num = arr[i], cnt = 0;
        for(int j = 0; j < n; j++){
            if(arr[i] > arr[j]){
                cnt++;
            }
        }
        ans[i] = cnt;
    }
    for(auto a: ans){
        cout << a << " ";
    }    
}


int main(){
    int n; 
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    smallerNumbersThanCurrent(arr);
}

/*
Input: nums = [8,1,2,2,3]
Output: [4,0,1,1,3]
*/