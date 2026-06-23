#include <bits/stdc++.h> 
using namespace std;

void printF(int i, vector<int> &ds, vector<int>& arr, int n, vector<vector<int>> &ans){
    if(i == n){
        ans.push_back(ds);
        return;
    }
    ds.push_back(arr[i]);
    printF(i + 1, ds, arr, n, ans);
    ds.pop_back();
    printF(i + 1, ds, arr, n, ans);
}

vector<vector<int>> pwset(vector<int>v)
{
    //Write your code here
    vector<int> ds;
    vector<vector<int>> ans;
    printF(0, ds, v, v.size(), ans);
    return ans;
}

int main(){
    vector<int> v = {3,1,2};
    vector<vector<int>> ans = pwset(v);
    for(auto &a : ans){
        for(auto &b : a)
        cout <<  "/" << b << "/ ";
        cout << endl;
    }
    return 0;
}