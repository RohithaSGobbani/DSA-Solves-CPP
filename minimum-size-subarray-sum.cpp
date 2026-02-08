#include<bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int>& arr) {
    int n = arr.size();
    int j = 0;
    int sum = 0, mini = INT_MAX;
    for(int i = 0; i < n; i++){
        sum += arr[i];
        while(sum >= target){
            mini = min(mini, i-j+1);
            sum -= arr[j];
            j++;
        }
    }
    if(mini == INT_MAX){
        mini = 0;
    }
    return mini;
}

/*
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
*/

int main(){
    int n,target; 
    cin >> n >> target;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << minSubArrayLen(target,arr);
}