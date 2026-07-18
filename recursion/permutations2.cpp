#include<bits/stdc++.h>
using namespace std;

void permute(int i, vector<int> &nums, vector<vector<int>> &ans){
    if(i == nums.size()){
        ans.push_back(nums);
        return;
    }
    unordered_set<int> used;
    for(int j = i; j < nums.size(); j++){
        if(used.count(nums[j])) continue;
        used.insert(nums[j]);
        swap(nums[i] , nums[j]);
        permute(i+1, nums, ans);
        swap(nums[i], nums[j]);
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    permute(0, nums, ans);
    return ans;        
}