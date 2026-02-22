#include<bits/stdc++.h>
using namespace std;

void floor(vector<int> &arr, int target){
    int n = arr.size();
    int low = 0, high = n-1;
    int ans = -1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] <= target){
            ans = arr[mid];
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    cout << ans;
}

void ceil(vector<int> &arr, int target){
    int n = arr.size();
    int low = 0, high = n-1;
    int ans = -1;
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
Input: arr = [10 20 30 40 50] target = 25
Output: floor = 20, ceil = 30
*/

int main(){
    int n;
    cin >> n; 
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    floor(arr,25);  
    ceil(arr,25)
}
