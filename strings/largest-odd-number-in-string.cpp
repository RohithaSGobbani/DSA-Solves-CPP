#include<bits/stdc++.h>
using namespace std;

string largestOddNumber(string num) {
    int n = num.size();
    while(!num.empty() && (num.back() - '0') % 2 == 0){
        num.pop_back();
    }
    return num;
}

/*
Input: num = "52"
Output: "5"
*/

int main(){
    string s;
    cin >> s;
    cout<< largestOddNumber(s);
    return 0;
}