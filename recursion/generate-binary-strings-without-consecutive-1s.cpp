#include<bits/stdc++.h>
using namespace std;

void generate(int n, string s, vector<string>& ans){
    if(s.length() == n){
        ans.push_back(s);
        return;
    }
    generate(n, s + "0", ans);
    if(s.empty() || s.back() != '1'){
        generate(n, s + "1", ans);
    }
}

void generateBinaryStrings(int n) {
    // Your code goes here
    vector<string> ans;
    generate(n, "", ans);

    for(auto &s: ans){
        cout << s << " ";
    }
}

int main(){
    int n;
    cin >> n;

    generateBinaryStrings(n);
    return 0;
}