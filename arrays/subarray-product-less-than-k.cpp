#include<bits/stdc++.h>
using namespace std;

int numSubarrayProductLessThanK(vector<int>& arr, int k) {
    int n = arr.size();
    int i = 0;
    int cnt = 0;
    while(i < n){
        int j = i;
        int prod = 1;
        while(j < n){
            prod *= arr[j];
            if(prod < k){
                cnt++;
            }else{
                break;
            }
            j++;
        }
        i++;
    }
    return cnt;
}

/*
Input: nums = [10,5,2,6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
*/

int main(){
    vector<int> arr = {10,5,2,6};
    int k = 100;
    cout << numSubarrayProductLessThanK(arr, k);
    return 0;
}