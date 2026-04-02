#include<bits/stdc++.h>
using namespace std;

int romanToInt(string s) {
    int n = s.size();
    unordered_map<char,int> mp = {
        {'I' , 1},
        {'V' , 5},
        {'X' , 10},
        {'L' , 50},
        {'C' , 100},
        {'D' , 500},
        {'M' , 1000}
    };
    int num = 0;
    for(int i = n-1; i >= 0; i--){
        if(i > 0 && mp[s[i-1]] < mp[s[i-1]]){
            if(s[i-1] == 'I' || s[i-1] == 'X' || s[i-1] == 'C')
                num -= 2 * mp[s[i]];
        }
        num += mp[s[i]];
    }
    return num;
}

/*
Input: s = "III"
Output: 3
*/

int main(){
    string s;
    cin >> s;
    cout << romanToInt(s);
}