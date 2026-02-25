#include<bits/stdc++.h>
using namespace std;

//Brute
int single(vector<int> &arr){
    int n = arr.size();
    if(n == 1) return arr[0];
    for(int i = 0; i < n; i++){
        if(i == 0){
            if(arr[i] != arr[i+1]) return arr[i];
        }else if(i == n-1){
            if(arr[i] != arr[i-1]) return arr[i];
        }else{
            if(arr[i] != arr[i-1] && arr[i] != arr[i+1]) return arr[i];
        }
    }
}

int singleNonDuplicate(vector<int>& arr) {
    int n = arr.size();
    if(n == 1) return arr[0];
    int low = 1, high = n - 2;
    while(low <= high){
        if(arr[0] != arr[1]) return arr[0];
        if(arr[n-1] != arr[n-2]) return arr[n-1];
        int mid = low + (high - low)/2;
        if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]){
            return arr[mid];
        }
        if((mid % 2 == 1 && arr[mid] == arr[mid-1]) || (mid % 2 == 0 && arr[mid] == arr[mid+1])){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return -1;
}

/*
Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
*/

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << single(arr);
    return 0;
}