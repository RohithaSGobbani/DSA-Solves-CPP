#include<bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
    int n = s.size();
    int right = n-1;
    string rev;
    while(right >= 0){
        string word;    
                    
        while(right >= 0 && s[right] == ' ') right--;
        if(right < 0) break;              
        int left = right;
        while(left >= 0 && s[left] != ' ') left--;
        for(int i = left+1; i <= right; i++){
            word += s[i];
        }
        right = left;
        if(!rev.empty()) rev += " ";
        rev += word;
    }          
    return rev;
}

/*
Input: s = "the sky is blue"
Output: "blue is sky the"
*/

int main(){
    string s;
    getline(cin,s);
    cout << s << endl;
    cout << reverseWords(s);
    return 0;
}