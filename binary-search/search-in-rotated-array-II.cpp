#include<bits/stdc++.h>
using namespace std;

bool search(vector<int>& arr, int target) {
    int n = arr.size();
    int low = 0, high = n-1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] == target) return true;
        if(arr[low] == arr[mid] && arr[mid] == arr[high]){
            low = low +1;
            high = high -1;
            continue;
        }
        if(arr[low] <= arr[mid]){
            if(arr[low] <= target && target <= arr[mid]){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }else{
            if(arr[mid] <= target && target <= arr[high]){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
    }
    return false;
}

/*
Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
*/

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << search(arr, 0);
    return 0;
}
