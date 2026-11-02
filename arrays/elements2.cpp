#include<bits/stdc++.h>
using namespace std;

int minMoves2(vector<int>& arr) {
    sort(arr.begin(),arr.end());
    int n = arr.size();
    int median = arr[n/2];
    int mvs = 0;
    for(int i = 0; i < n; i++){
       if(arr[i] < median){
            mvs += median - arr[i];
       }
       if(arr[i] > median){
            mvs += arr[i] - median;
       }
    }
    return mvs;
}

int main(){
    vector<int> arr = {1,0,0,8,6};
    int ans = minMoves2(arr);
    cout << ans;
    return 0;
}