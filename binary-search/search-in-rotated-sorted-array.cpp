#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& arr, int target) {
    int n = arr.size();
    int low = 0, high = n-1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] == target) return mid;
        //left is sorted
        if(arr[low] <= arr[mid]){
            if(arr[low] <= target && target <= arr[mid]){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        //right is sorted
        else{
            if(arr[mid] <= target && target <= arr[high]){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
    }
    return -1;
}

/*
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
*/

int main(){
    int n;
    cin >> n; 
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    search(arr,0);   
}
