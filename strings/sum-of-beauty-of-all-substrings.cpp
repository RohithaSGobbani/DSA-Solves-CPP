#include<bits/stdc++.h>
using namespace std;

int beautySum(string s) {
    int n = s.size();
    int sum = 0;
    for(int i = 0; i < n; i++){
        unordered_map<char,int> freq;
        for(int j = i; j < n; j++){
            freq[s[j]]++;
            int mini = INT_MAX;
            int maxi = INT_MIN;
            for(auto a: freq){
                mini = min(mini, a.second);
                maxi = max(maxi,a.second);
            }
            sum += (maxi - mini);
        }
    }
    return sum;
}

/*
Input: s = "aabcb"
Output: 5
*/

int main(){
    string s;
    cin >> s;
    cout << beautySum(s);
    return 0;
}