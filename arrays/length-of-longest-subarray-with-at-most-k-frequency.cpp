#include<bits/stdc++.h>
using namespace std;

int maxSubarrayLength(vector<int>& arr, int k) {
        int n = arr.size();

        int i = 0, j = 0;
        int len = 0;
        unordered_map<int,int> mp;
        while(i < n){
            mp[arr[j]]++;
            while(mp[arr[j]] > k){
                // len = max(len, j-1-i+1);
                if(i < n) mp[arr[i]] -= 1;
                i++;
            }
            len = max(len, j-i+1);
            if(j<n-1) j++;
        }
        return len;
}

int main(){
	vector<int> arr = {1,2,1,2,1,2,1};
	int k = 2;
	cout << maxSU=ubarrayLength(arr,k);
	return 0;
}
