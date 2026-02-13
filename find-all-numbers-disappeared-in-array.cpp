#include<bits/stdc++.h>
using namespace std;

/*
Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]
*/

void findMissingBrute(vector<int> &arr){
    int repeating = -1, missing = -1;
    for(int i = 1; i < n; i++){
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(arr[j] == i){
                cnt++;
            }
        }
        if(cnt == 2) repeating = i;
        else if(cnt == 0) missing = i;
        if(repeating != -1 && missing != -1) break;
    }
}

void findDisappearedNumbers(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans;
    for(int i = 0; i < n; i++){
        int idx = abs(nums[i]) - 1;
        if(nums[idx] > 0){
            nums[idx] = -nums[idx];
        }
    }
    for(int i = 0; i < n; i++){
        if(nums[i] > 0){
            ans.push_back(i+1);
        }
    }
    for(auto a: ans){
        cout << a << " ";
    }
}

int main(){
    int n; 
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    findDisappearedNumbers(arr);
}
