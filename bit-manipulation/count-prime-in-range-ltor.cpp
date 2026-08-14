#include<bits/stdc++.h>
using namespace std;

vector<int> primesInRange(vector<vector<int>>& queries){
            //your code goes here
            if (queries.empty()) {
                return {};
            }

            int n = queries.size();
            vector<int> ans;
            for(int q = 0; q < n; q++){
                int l = queries[q][0];
                int r = queries[q][1];
                int cnt = 0;
                int prime[r+1];
                for(int i = 0; i <= r; i++){
                    prime[i] = 1;
                }

                if (r >= 0) prime[0] = 0;
                if (r >= 1) prime[1] = 0;

                for(int i = 2; i*i <= (r); i++){
                    if(prime[i] == 1){
                        for(int j = i*i; j <= r; j+=i){
                            prime[j] = 0;
                        }
                    }
                }
                for(int i = l; i <= r; i++){
                    if(i<2) continue;
                    if(prime[i] == 1) cnt++;
                }
                ans.push_back(cnt);
            }
            return ans;
}

int main(){
	vector<vector<int>> arr = [[1,4],[4,8]];
	vector<int> ans = primesInRange(arr);
	for(auto a: ans){
		cout << a << " ";
	}
	return 0;
}
