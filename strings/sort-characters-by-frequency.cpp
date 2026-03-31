#include<bits/stdc++.h>
using namespace std;

string frequencySort(string s) {
    int n = s.size();
    unordered_map<char, int> mp;
    for(int i = 0; i < n; i++){
        mp[s[i]]++;
    }
    
    string s1;
    vector<pair<int, char>> freqVec;
    for(auto &it : mp){
        freqVec.push_back({it.second,it.first});
    }
    sort(freqVec.begin(),freqVec.end(), greater<pair<int, char>>());
    for(auto &it: freqVec){
        s1.append(it.first,it.second);
    }
    return s1;
}

/*
Input: s = "tree"
Output: "eert"
*/

int main(){
    string s;
    cin >> s;
    cout << frequencySort(s);
    return 0;
}