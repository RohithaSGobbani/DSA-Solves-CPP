#include <bits/stdc++.h>
using namespace std;

//Brute
void sort012(vector<int> &arr){
    int n = arr.size();
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == 0) cnt0++;
        else if(arr[i] == 1) cnt1++;
        else cnt2++;
    }
    for(int i = 0; i < cnt0; i++) arr[i] = 0;
    for(int i = cnt0; i < cnt0 + cnt1; i++) arr[i] = 1;
    for(int i = cnt0 + cnt1; i < n; i++) arr[i] = 2;
    for(auto a : arr){
        cout << a << " ";
    }
}

//Optimal
void sortColors(vector<int>& nums) {
    int n = nums.size();
    int low = 0, mid = 0, high = n-1;
    while(mid <= high){
        if(nums[mid] == 0){
            swap(nums[mid], nums[low]);
            low++;
            mid++;
        }
        else if(nums[mid] == 1) mid++;

        else if(nums[mid] == 2){
            swap(nums[mid], nums[high]);
            high--;
        }
    }
    for(auto a : nums){
        cout << a << " ";
    }    
}

"""
Input: arr = [0,1,2,0,1,2,1,2,0,0,0,1]
Output: [0,0,0,0,0,1,1,1,1,2,2,2]
"""

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    //sort012(arr);
    sortColors(arr);
    return 0;
}