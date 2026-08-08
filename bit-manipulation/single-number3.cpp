#include<bits/stdc++.h>
using namespace std;

vector<int> singleNumber(vector<int>& nums){
			//your code goes here
            long xorr = 0;
            int n = nums.size();
            for(int i = 0; i < n; i++){
                xorr ^= nums[i];
            }
        int rightmost = (xorr & (xorr-1)) ^ xorr;
            int b1=0, b2=0;
            for(int i = 0; i < n; i++){
                if(nums[i] & rightmost) b1 = b1 ^ nums[i];
        	else b2 = b2 ^ nums[i];
             }
	if(b1 < b2) return {b1, b2};
	else return {b2, b1};
}

int main(){
	vector<int> arr = {2,4,2,14,3,7,7,3};
	cout << singleNumber(arr);
	return 0;
}
