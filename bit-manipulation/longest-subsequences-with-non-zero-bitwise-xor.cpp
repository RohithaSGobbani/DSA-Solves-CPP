#include<bits/stdc++.h>
using namespace std;

int longestSubsequence(vector<int>& arr) {
        int n = arr.size();
        if(n == 1){
            if(arr[0] == 0) return 0;
            else return 1;
        }
        int i = 0;
        int xr = 0;
        int cnt = 0;
        while(i < n){
            if(arr[i] == 0) cnt++;
            if(i < n) xr ^= arr[i++];
        }
        if(xr > 0) return n;
        if(cnt == n) return 0;
        i = 0;
        while(xr == 0){
            if(arr[i] == 0) continue;
            if(i < n) xr ^= arr[i++];
        }
        if(xr == 0) return 0;
        else return n-i;
}

int main(){
	vector<int> arr = {1,2,3};
	cout << longestSubsequence(arr);
	return 0;
}
