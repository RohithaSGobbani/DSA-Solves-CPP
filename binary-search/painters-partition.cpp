#include<bits/stdc++.h>
using namespace std;

int sum(vector<int> &arr, int sum){
    int cntk = 1, larsum = 0;
    int n = arr.size();
    for(int i = 0; i < n; i++){
        if(larsum + arr[i] <= sum){
            larsum += arr[i];
        }else{
            cntk++;
            larsum = arr[i];
        }
    }
    return cntk;
}
int splitArray(vector<int>& arr, int k) {
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);
    int n = arr.size();
    if(k > n) return -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(sum(arr,mid) <= k){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return low;
}

/*
Input: nums = [7,2,5,10,8], k = 2
Output: 18
*/

int main(){
    int n;
    cin >> n; 
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int k;
    cin >> k;
    cout << splitArray(arr, k);
}