#include<bits/stdc++.h>
using namespace std;

/*
Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]
*/

//Brute
void findMissingBrute(vector<int> &arr){
    int repeating = -1, missing = -1;
    for(int i = 1; i < n; i++){
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(arr[j] == i){
                cnt++;
            }
        }
        if(cnt == 2) repeating = i;
        else if(cnt == 0) missing = i;
        if(repeating != -1 && missing != -1) break;
    }
}

//Better
void findMissingBetter(vector<int> &arr){
    int n = arr.size();
    int hash[n+1] = {0};
    int repeating = -1, missing = -1;
    for(int i = 0; i < n; i++){
        hash[arr[i]]++;
    }
    for(int i = 1; i < n; i++){
        if(hash[i] == 2){
            repeating = i;
        }else if(hash[i] == 0){
            missing = i;
        }
        if(repeating != -1 && missing != -1) break;
    }
}

//Optimal1: Maths
void findmissing(vector<int> &arr){
    long long n = arr.size();
    long long sn = (n * (n+1))/ 2;
    long long sn2 = ((n * (n+1) * (2 * n + 1)) / 6);
    long long s = 0, s2 =  0;
    for(int i = 0; i < n; i++){
        s += arr[i];
        s2 += (long long)arr[i] * (long long)arr[i];
    }
    long long val1 = s - sn;
    long long val2 = s - sn2;
    val2 = val2 / val1;
    long long x = (val1+val2) / 2;
    long long y = x - val1;
    cout << (int)x << (int)y;
}

//Optimal2: XOR
void findmissingXOR(vector<int> &arr){
    int n = arr.size();
    int xr = 0;
    for(int i = 0; i < n; i++){
        xr = xr ^ arr[i];
        xr = xr ^ (i+1);
    }
    int bitno = 0;
    while(1){
        if((xr & (1 << bitno)) != 0){
            break;
        }
        bitno++;
    }
    int zero = 0;
    int one = 0;
    for(int i = 0; i < n; i++){
        //part of zero group
        if((arr[i] & (1 << bitno)) == 0){
            zero = zero ^ arr[i];
        }
        //part of one group
        else{
            one = one ^ arr[i];
        }
    }

    for(int i = 1; i <= n; i++){
        //part of zero group
        if((i & (1 << bitno)) == 0){
            zero = zero ^ i;
        }
        //part of one group
        else{
            one = one ^ i;
        }
    }

    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == zero) cnt++;
    }
    if(cnt == 2) return {zero, one};
    return {one, zero};
}

void findDisappearedNumbers(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans;
    for(int i = 0; i < n; i++){
        int idx = abs(nums[i]) - 1;
        if(nums[idx] > 0){
            nums[idx] = -nums[idx];
        }
    }
    for(int i = 0; i < n; i++){
        if(nums[i] > 0){
            ans.push_back(i+1);
        }
    }
    for(auto a: ans){
        cout << a << " ";
    }
}

int main(){
    int n; 
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    findDisappearedNumbers(arr);
}
