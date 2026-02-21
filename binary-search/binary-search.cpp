#include<bits/stdc++.h>
using namespace std;

//Iterative
int bs(vector<int> &arr, int t){
    int n = arr.size();
    int low = 0, high = n-1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == t) return mid;
        else if(arr[mid] < t) low = mid+1;
        else high = mid - 1;
    }
    return -1;
}

//Recursive
int bsRecursive(vector<int> &arr, int low, int high, int t){
    if(low > high) return -1;
    int mid = (low+high)/2;
    if(arr[mid] == t) return mid;
    else if(arr[mid] < t)
        return bsRecursive(arr,mid+1, high , t);
    else
        return bsRecursive(arr, low, mid-1, t);
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << bsRecursive(arr,0,n-1, 6);
    return 0;
}
