#include<bits/stdc++.h>
using namespace std;

const int INT_MIN_VAL = -2147483648;
const int INT_MAX_VAL = 2147483647; 
int helper(const string &s, long long num, int i, int sign){
    if(i >= s.size() || !isdigit(s[i]))
        return (int)(num * sign);
    num = num * 10 + (s[i] - '0');
    if(sign * num <= INT_MIN_VAL) return INT_MIN_VAL;
    if(sign * num >= INT_MAX_VAL) return INT_MAX_VAL;
    return helper(s, num, i+1, sign);
}
int myAtoi(string s) {
    int n = s.size();
    int i = 0;
    while(i < n && s[i] == ' ') i++;
    int sign = 1;
    if(i < n && (s[i] == '+' || s[i] == '-')){
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }
    return helper(s,0, i, sign);
}

/*
Input: s = " -042"
Output: -42
*/

int main(){
    string s;
    cin >> s;
    cout << myAtoi(s);
}