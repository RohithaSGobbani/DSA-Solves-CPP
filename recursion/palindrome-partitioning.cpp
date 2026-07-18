#include <bits/stdc++.h> 

bool ispal(string &s, int start, int end){
    while(start <= end){
        if(s[start++] == s[end--]) continue;
        else return false;
    }
    return true;
}

void func(int i, string &s, vector<string> &path, vector<vector<string>> &ans){
    if(i == s.size()){
        ans.push_back(path);
        return;
    }

    for(int j = i; j < s.size(); j++){
        if(ispal(s, i, j)){
            path.push_back(s.substr(i, j - i + 1));
            func(j+1, s, path, ans);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s) 
{
    // Write your code here.
    vector<vector<string>> ans;
    vector<string> path;

    func(0, s, path, ans);
    return ans;
}