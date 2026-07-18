#include<bits/stdc++.h>
using namespace std;

int findGCD(vector<int>& arr) {
    int n = arr.size();
    int small = INT_MAX;
    int large = INT_MIN;
    for(int i = 0; i < n; i++){
        if(small > arr[i]) small = arr[i];
        if(large < arr[i]) large = arr[i];
    }
    int gcd;
    while(large > small){
        if(small == 0){
            gcd = large;
            break;
        }
        int temp = small;
        small = large % small;
        large = temp;
    }
    return gcd;
}

/*
Input: nums = [2,5,6,9,10]
Output: 2
Explanation:
The smallest number in nums is 2.
The largest number in nums is 10.
The greatest common divisor of 2 and 10 is 2.
*/

int main(){

    vector<int> arr = {2,5,6,9,10};
    int gcd = findGCD(arr);
    cout << gcd;
    return 0;
}