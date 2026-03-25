#include<bits/stdc++.h>
using namespace std;

bool isPalindromeBrute(string s) {
    if(s == " " || s == "") return true;
    string s1;
    for(auto a: s){
        if(isalnum(a)){
            s1+=tolower(a);
        }
    }
    string rev;
    int n = s1.size();
    for(int i = n-1; i >= 0; i--){
        rev+=s1[i];
    }
    if(s1 == rev) return true;
    else return false;
}

/*
Input: s = "A man, a plan, a canal: Panama"
Output: true
*/

int main(){
    string s;
    cin >> s;
    if(isPalindromeBrute(s)) cout << "true";
    else cout << "false";
}