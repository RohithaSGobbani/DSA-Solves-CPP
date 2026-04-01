#include<bits/stdc++.h>
using namespace std;

int maxDepth(string s) {
    int n = s.size();
    int cnt = 0;
    int maxi = INT_MIN;
    for(int i = 0; i < n; i++){
        if(s[i] == '('){
            cnt++;
        }else if(s[i] == ')'){
            cnt--;
        }
        maxi = max(maxi,cnt);
    }
    return maxi;
}

/*
Input: s = "(1+(2*3)+((8)/4))+1"
Output: 3
*/

int main(){
    string s;
    cin >> s;
    cout << maxDepth(s);
    return 0;
}