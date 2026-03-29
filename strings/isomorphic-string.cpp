#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t) {
    int n = s.size();
    unordered_map<char,char> mp;
    unordered_set<char> assigned;
    for(int i = 0; i < n; i++){
        if(mp.find(s[i]) != mp.end()) {
            if(mp[s[i]] != t[i])
                return false;
        }else{
            if(assigned.find(t[i]) == assigned.end())
                assigned.insert(t[i]);
            else return false;
        }
        mp[s[i]] = t[i];
    }
    return true;
}

/*
Input: s = "egg", t = "add"
Output: true
*/

int main(){
    string s, t;
    cin >> s >> t;
    cout << isIsomorphic(s,t);
    return 0;
}