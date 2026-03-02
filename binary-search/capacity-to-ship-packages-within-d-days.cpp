#include<bits/stdc++.h>
using namespace std;

int totaldays(vector<int> &arr, int capacity){
    int n = arr.size();
    int total = 0;
    int cntdays = 1;
    for(int i = 0; i < n; i++){
        if(total + arr[i] > capacity){
            cntdays++;
            total = arr[i];
        }else{
            total += arr[i];
        }
    }
    return cntdays;
}
int shipWithinDays(vector<int>& arr, int days) {
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);
    while(low <= high){
        int mid = low + (high - low)/2;
        if(totaldays(arr,mid) <= days){
            high = mid - 1;
        }else{
            low = mid+1;
        }
    }
    return low;
}

/*
Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
*/

int main(){
    int n;
    cin >> n; 
    vector<int> arr(n);
    int days;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cin >> days;
    cout << shipWithinDays(arr, days);    
}

