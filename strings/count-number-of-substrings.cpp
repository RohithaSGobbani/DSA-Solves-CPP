#include<bits/stdc++.h>
using namespace std;

int atMostDistinct(string s, int k){
    int left = 0, res = 0;

    unordered_map<char,int> freq;
    int n = s.size();
    for(int right = 0; right < n; right++){
        freq[s[right]]++;

        while(freq.size() > k){
            freq[s[left]]--;
            if(freq[s[left]] == 0) freq.erase(s[left]);
            left++;
        }

        res += (right - left + 1);
    }
    return res;
}

/*
Input: s = "pqpqs", k = 2  
Output: 7 
*/

int main(){
    string s;
    cin >> s;
    int k;
    cin >> k;
    cout << atMostDistinct(s, k) - atMostDistinct(s,k-1);
}