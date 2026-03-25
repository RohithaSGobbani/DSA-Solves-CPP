#include<bits/stdc++.h>
using namespace std;

//Brute
bool isPalindromeBrute(string s) {
    if(s == " " || s == "") return true;
    string s1;
    for(auto a: s){
        if(isalnum(a)){
            s1+=tolower(a);
        }
    }
    string rev;
    int n = s1.size();
    for(int i = n-1; i >= 0; i--){
        rev+=s1[i];
    }
    if(s1 == rev) return true;
    else return false;
}

//Optimal
bool isPalindrome(string s) {
    string s1;
    for(auto a: s){
        if(isalnum(a)){
            s1+=tolower(a);
        }
    }
    int left = 0, right = s1.size()-1;        
    while(left < right){
        if(s1[right] != s1[left]) return false;
        left++;
        right--;
    }
    return true;
}

/*
Input: s = "A man, a plan, a canal: Panama"
Output: true
*/

int main(){
    string s;
    cin >> s;
    if(isPalindrome(s)) cout << "true";
    else cout << "false";
}