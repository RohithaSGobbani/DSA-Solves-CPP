#include<bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}

bool isAnagram2(string s, string t) {
    multiset<char> st;
    int n = s.size();
    int n2 = t.size();
    if(n != n2) return false;
    for(int i = 0; i < n; i++){
        st.insert(s[i]);
    }
    for(int i = 0; i < n; i++){
        auto it = st.find(t[i]);
        if(it != st.end()){
            st.erase(it);
        }
    }
    return st.empty();
}

bool isAnagramO(string s, string t) {
    if(s.size() != t.size()) return false;
    int freq[26] = {0};
    for(int i = 0; i < s.size(); i++){
        freq[s[i] - 'a']++;
        freq[t[i] - 'a']--;
    }
    for(int i = 0; i < 26; i++){
        if(freq[i] != 0) return false;
    }
    return true;
}

/*
Input: s = "anagram", t = "nagaram"
Output: true
*/

int main(){
    string s, t;
    cin >> s >> t;
    cout << isAnagramO(s,t);
}