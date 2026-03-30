#include <bits/stdc++.h>
using namespace std;

string rotate(string s, int n, int d){
    reverse(s.begin(), s.begin()+d);
    reverse(s.begin()+d, s.begin()+n);
    reverse(s.begin(), s.end());
    return s;
}
bool rotateString(string s, string goal) {
    int n = s.size();
    for(int i = 0;i < n; i++){
        if(goal == rotate(s,n,i)){
            return true;
        }
    }
    return false;
}

/*
Input: s = "abcde", goal = "cdeab"
Output: true
*/

int main(){
    string s, goal;
    cin >> s >> goal;
    cout << rotateString(s,goal);
}