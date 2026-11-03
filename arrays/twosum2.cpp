#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& arr, int target) {
    int n = arr.size();
    int low = 0, high = n-1;
    while(low < high){
        if(arr[low]+arr[high] == target) return {low+1, high+1};
        else if(arr[low]+arr[high] < target) low++;
        else high--;
    }
    return {-1,-1};
}

int main(){
    vector<int> arr = {2,7,11,15};
    int target = 9;
    vector<int> ans = twoSum(arr, target);
    for(auto a : ans){
        cout << a << " ";
    }
    return 0;
}