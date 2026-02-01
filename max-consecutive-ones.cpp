#include<bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int max1 = 0, cnt = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == 1){
            cnt++;
            max1 = max(max1, cnt);
        }
        else cnt = 0;
    }
    return max1;
}

"""
Input: nums = [1,1,0,1,1,1]
Output: 3
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