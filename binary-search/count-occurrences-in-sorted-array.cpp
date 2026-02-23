#include<bits/stdc++.h>
using namespace std;

int firstOccurence(vector<int> &arr, int target){
    int n = arr.size();
    int low = 0, high = n-1;
    int first = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] == target){
            first = mid;
            high = mid-1;
        }else if(arr[mid] < target){
            low = mid+1;
        }else{
            high = mid -1;
        }
    }
    return first;
}

int lastOccurence(vector<int> &arr, int target){
    int n = arr.size();
    int low = 0, high = n-1;
    int last = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] == target){
            last = mid;
            low = mid + 1;
        }else if(arr[mid] < target){
            low = mid+1;
        }else{
            high = mid -1;
        }
    }
    return last;
}

int main(){
    int n;
    cin >> n; 
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int first = firstOccurence(arr,9);   
    int last = lastOccurence(arr,9);
    cout<<  (lastOccurence - firstOccurence + 1);
}
