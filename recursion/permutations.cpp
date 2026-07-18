#include<bits/stdc++.h>
using namespace std;

void permute(vector<int> &ds, vector<int> &nums, int freq[], vector<vector<int>> &ans){
    if(ds.size() == nums.size()){
        ans.push_back(ds);
        return;
    }
    for(int j = 0; j < nums.size(); j++){
        if(freq[j] != 0) continue;
        ds.push_back(nums[j]);
        freq[j] = 1;
        permute(ds, nums, freq, ans);
        ds.pop_back();
        freq[j] = 0;
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> ds;
    int freq[nums.size()];
    for(int i = 0; i < nums.size(); i++) freq[i] = 0;
    permute(ds, nums, freq, ans);
    return ans;
}

/*
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/
