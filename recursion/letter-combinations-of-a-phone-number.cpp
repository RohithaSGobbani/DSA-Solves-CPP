#include<bits/stdc++.h>
using namespace std;

void findComb(int i, string current, vector<int> &nums, vector<string> &table, vector<string> &ans){
    if(i == nums.size()){
        ans.push_back(current);
        return;
    }
    int n = nums[i];
    string str = table[n];
    for(int j = 0; j < str.size(); j++){
        current += str[j];
        findComb(i + 1, current, nums, table, ans);
        current.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> ans;
    vector<string> table = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<int> nums;
    string current = "";
    for(auto a: digits){
        int num = a - '0';
        nums.push_back(num);
    }
    findComb(0, current, nums, table, ans);
    return ans;
}

int main(){
    string digits;
    cin >> digits;
    vector<string> ans = letterCombinations(digits);
    for(auto a : ans){
        cout << a << " ";
    }
    return 0;
}