#include<bits/stdc++.h>
using namespace std;

int findKRotation(vector<int> &arr)  {
    int n = arr.size();
    int low = 0, high = n-1;
    int mini = INT_MAX;
    int index = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[low] <= arr[high]){
            if(arr[low] < mini){
                index = low;
                mini = arr[low];
            }
            break;
        }
        if(arr[low] <= arr[mid]){
            if(arr[low] < mini){
                index = low;
                mini = arr[low];
            }
            low = mid+1;
        }else{
            if(arr[mid] < mini){
                index = mid;
                mini = arr[mid];
            }
            high = mid-1;
        }
    }
    return index;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << findKRotation(arr);
    return 0;
}