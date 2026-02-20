#include<bits/stdc++.h>
using namespace std;

double findMaxAverage(vector<int>& arr, int k) {
    int n = arr.size();           
    int currsum = 0;
    for(int i = 0; i < k; i++){
        currsum += arr[i];
    }   
    int maxsum = currsum;
    for(int i = k; i < n; i++){
        currsum += arr[i] - arr[i-k];
        maxsum = max(maxsum, currsum);
    }
    return (double)maxsum/k;
}

/*
Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
*/

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << findMaxAverage(arr,4);
    return 0;
}