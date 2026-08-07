#include<bits/stdc++.h>
using namespace std;

//Brute
string convert2Bin(int num){
        string ans = "";
        while(num > 0){
            if(num % 2 == 1) ans += '1';
            else ans += '0';
            num = num / 2;
        }
        while(ans.size() != 32) ans += '0';
        reverse(ans.begin(),ans.end());
        return ans;
    }
    int minBitFlips(int start, int goal) {
        string st = convert2Bin(start);
        string go = convert2Bin(goal);
        int cnt = 0;
        cout << st << " " << go;
        int n1 = st.size();
        int n2 = go.size();
        while(n1 >= 0 && n2 >= 0){
            if(st[n1] != go[n2]) cnt++;
            n1--;
            n2--;
        }
        return cnt;
}

//Optimal
int minBitFlipsOptimal(int start, int goal) {
        int ans = start ^ goal;
        int cnt = 0;
        while(ans > 0){
            if(ans % 2 == 1) cnt++;
            ans = ans / 2;
        }
        return cnt;
}

int main(){
	cout << minBitFlips(32, 14);
	return 0;
}
