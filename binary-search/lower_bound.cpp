#include<bits/stdc++.h>
using namespace std;

void lowerBound(vector<int> &arr, int target){
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
    cout << ans;
}

/*
Input: arr = [1 3 4 5 7 8 9 9 9 11] target = 9
Output: 
*/

int main(){
    int n;
    cin >> n; 
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    lowerBound(arr,9);   
}