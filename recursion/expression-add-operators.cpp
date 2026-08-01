#include<bits/stdc++.h>
using namespace std;

void solve(string &num, int i, long long target, long long op, long long prev, string &s, vector<string> &ans){
        if(i == num.size()){
            if(op == target){
                ans.push_back(s);
                return;
            }else{
                return;
            }
        }
        for(int k = i; k < num.size(); k++){
            if(k > i && num[i] == '0') break;

            string part = num.substr(i,k-i+1);
            long long val = stoll(part);

            if(i == 0){
                int lenBefore = s.size();
                s += part;
                solve(num,k+1,target,val,val,s,ans);
                s.resize(lenBefore);
                continue;
            }
        for(int j = 0; j < 3; j++){
            int lenBefore = s.size();
            if(j == 0){
                s += '+';
                s += part;

                solve(num, k+1,target,op+val,val,s,ans);
                s.resize(lenBefore);
            }
            else if(j == 1){
                s += '-';
                s += part;

                solve(num, k+1,target,op-val,-val,s,ans);
                s.resize(lenBefore);
            }
            else if(j == 2){
                s += '*';
                s += part;
                solve(num, k+1,target,(op-prev)+(prev*val),prev*val,s,ans);
                s.resize(lenBefore);
            }
        }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        if(num.empty()) return ans;
        string s = "";
        int op = 0;
        int i = 0;
        solve(num, i,(long long)target,op,0,s,ans);
        return ans;
    }

int main(){
	string s = "123";
	int target = 6;
	vector<string> ans = addOperators(s,target);
	return 0;
}

