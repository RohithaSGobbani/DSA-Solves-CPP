#include<bits/stdc++.h>
using namespace std;

long long dividedsum(vector<int> &arr, int num){
    long long sum = 0;
    int n = arr.size();
    for(int i = 0; i < n; i++){
        sum += (arr[i] + num - 1)/num;
    }
    return sum;
}
int smallestDivisor(vector<int>& arr, int threshold) {
    int low = 1, high = *max_element(arr.begin(),arr.end());
    if(dividedsum(arr,1) <= threshold) return 1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(dividedsum(arr,mid) <= threshold){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return low;
}

/*
Input: nums = [1,2,5,9], threshold = 6
Output: 5
*/

int main(){
    int n;
    cin >> n; 
    int threshold;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cin >> threshold;
    cout << smallestDivisor(arr, threshold);    
}