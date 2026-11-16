#include<bits/stdc++.h>
using namespace std;

string digitSum(string s, int k) {
        string ans;
        while(s.size() > k){
            ans = "";
            int i = 0;
            while(i < s.size()){
                int n = 0;
                for(int j = i;j < s.size() && j < i+k; j++){
                    n += s[j] - '0';
                }
                ans += to_string(n);
                i += k;
            }
            s = ans;
        }
        return s;
    }

int main(){
	string s = "11111222221";
	int k = 3;
	cout << digitSum(s,k);
	return 0;
}
