#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = (n * (n+1)) / 2;
        int s2 = 0; 
        for(int i = 0; i < n; i++){
            s2 += nums[i];
        }
        return sum - s2;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }    
    missingNumber(arr, n);
}