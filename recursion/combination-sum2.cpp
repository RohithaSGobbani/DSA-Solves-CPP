#include<bits/stdc++.h>
using namespace std;

    void combSum(int i, vector<int>& ds, vector<int> &arr, int n, int s, vector<vector<int>> &ans){
        if(s == 0){
            ans.push_back(ds);
            return;
        }

        for(int j = i; j < n; j++){
            if(j > i && arr[j] == arr[j-1]) continue;
            if(arr[j] > s) break;

            ds.push_back(arr[j]);
            combSum(j + 1, ds, arr, n, s - arr[j], ans);
            ds.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int s) {
        vector<int> ds;
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        combSum(0, ds, arr, arr.size(), s, ans);
        return ans;
    }

int main(){
    vector<int> cand = {2,5,2,1,2};
    int target = 5;
    vector<vector<int>> ans = combinationSum2(cand, target);
    for(auto &a: ans){
        for(auto &b: a){
            cout << b << " ";
        }
        cout << endl;
    }
    return 0;
}