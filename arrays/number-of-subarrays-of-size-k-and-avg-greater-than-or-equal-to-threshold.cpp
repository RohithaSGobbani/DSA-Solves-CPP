#include<bits/stdc++.h>
using namespace std;

int numOfSubarrays(vector<int>& arr, int k, int threshold) {
    int n = arr.size();
    int cursum = 0;
    int cnt = 0;
    for(int i = 0; i < k; i++){
        cursum += arr[i];
    }
    if((double)cursum/k >= threshold) cnt++;
    for(int i = k; i < n; i++){
        cursum += arr[i] - arr[i-k];
        double avg = (double)cursum / k;
        if(avg >= threshold){
            cnt++;
        }           
    }
    return cnt;
}

/*
Input: arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
Output: 3
*/

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << numOfSubarrays(arr, 3, 4);
    return 0;
}