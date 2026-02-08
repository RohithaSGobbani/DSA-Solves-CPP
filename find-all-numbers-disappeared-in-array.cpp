#include<bits/stdc++.h>
using namespace std;

/*
Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]
*/

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