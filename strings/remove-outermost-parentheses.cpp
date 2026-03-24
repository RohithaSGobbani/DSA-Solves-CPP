#include<bits/stdc++.h>
using namespace std;

string removeOuterParentheses(string s) {
    int n = s.size();
    int cnt = 0;
    string res;
    for(int i = 0; i < n; i++){
        if(s[i] == '('){
            if(cnt > 0){
                res+=s[i];
            }
            cnt++;
        }else{
            cnt--;
            if(cnt > 0){
                res+=s[i];
            }
        }
    }
    return res;
}

/*
Input: s = "(()())(())"
Output: "()()()"
*/

int main(){ 
    string s;
    cin >> s;
    string res = removeOuterParentheses(s);
    cout << res;
}