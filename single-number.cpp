#include<bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    int ans=0;
    for(int val: nums){
        ans^=val;
    }
    return ans;
}

"""
Input: nums = [4,1,2,1,2]
Output: 4
"""

int main(){
    int n; 
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    } 
    cout << findMaxConsecutiveOnes(arr);
    return 0;    
}