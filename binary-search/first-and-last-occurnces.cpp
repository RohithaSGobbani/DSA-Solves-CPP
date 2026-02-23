#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &arr, int target){
    int n = arr.size();
    int low = 0, high = n-1;
    int ans = n;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] >= target){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return ans;
}
int upperBound(vector<int> &arr, int target){
    int n = arr.size();
    int low = 0, high = n-1;
    int ans = n;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] > target){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return ans;
}
vector<int> searchRange(vector<int>& arr, int target) {
    int n = arr.size();
    int lb = lowerBound(arr,target);
    int ub = upperBound(arr,target);

    if((lb == n) || (arr[lb] != target)) return {-1,-1};
    return {lb, ub-1};
}   

/*
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
*/

int main(){
    int n;
    cin >> n; 
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << searchRange(arr,9);   
}
