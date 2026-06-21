#include<bits/stdc++.h>
using namespace std;

void generate(vector<string>& ans, string s, int open , int close, int n){
    if(open == n && close == n){
        ans.push_back(s);
        return;
    }
    if(open < n){
        generate(ans, s + "(", open+1, close, n);
    }
    if(close < open){
        generate(ans, s + ")", open, close+1, n);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> ans;
    int open = 0;
    int close = 0;
    generate(ans, "", open, close, n);
    return ans;
}

int main (){
    int n;
    cin >> n;
    vector<string> ans = generateParenthesis(n);
    for(auto &s: ans){
        cout << s << " ";
    }
    return 0;
}