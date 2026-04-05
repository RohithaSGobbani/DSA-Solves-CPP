#include<bits/stdc++.h>
using namespace std;

int helper(string s, int left, int right){
    while(left >= 0 && right < s.size() && s[left] == s[right]){
        left--;
        right++;
    }
    return right - left - 1;
}
string longestPalindrome(string s) {
    int n = s.size();
    if(n <= 1) return s;
    int start = 0;
    int maxLen = 1;
    for(int i = 0; i < n; i++){
        int len1 = helper(s,i,i);
        int len2 = helper(s,i,i+1);
        int len = max(len1, len2);
        if(len > maxLen){
            maxLen = len;
            start = i - (len - 1)/2;
        }
    }
    return s.substr(start,maxLen);
}

/*
Input: s = "babad"
Output: "bab"
*/

int main(){
    string s;
    cin >> s;
    cout << longestPalindrome(s);
    return 0;
}