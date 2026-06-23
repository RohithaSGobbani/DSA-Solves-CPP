#include<bits/stdc++.h>
using namespace std;

void combSum(int i, vector<int>& ds, vector<int> &cand, int n, int target,  vector<vector<int>> &ans){
    if(i == n){
        if(target == 0){
            ans.push_back(ds);
        }
        return;
    }
    if(cand[i] <= target){
        ds.push_back(cand[i]);
        combSum(i, ds, cand, n, target-cand[i], ans);
        ds.pop_back();
    }
    combSum(i + 1, ds, cand, n, target, ans);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
   vector<vector<int>> ans;
   vector<int> ds;
   combSum(0, ds,  candidates, candidates.size(), target, ans) ;
   return ans;
}

int main(){
    vector<int> cand = {2,3,6,7};
    int target = 7;
    vector<vector<int>> ans = combinationSum(cand, target);
    for(auto &a: ans){
        for(auto &b: a){
            cout << b << " ";
        }
        cout << endl;
    }
    return 0;
}