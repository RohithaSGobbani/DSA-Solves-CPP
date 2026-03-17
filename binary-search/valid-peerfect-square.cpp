#include<bits/stdc++.h>
using namespace std;

bool isPerfectSquare(int num) {
    int low = 0, high = num;
    while(low <= high){
        int mid = low + (high - low)/2;
        if((long long)mid*mid > num){
            high = mid-1;
        }else if((long long)mid*mid == num) return true;
        else low = mid+1;
    }
    return false;
}

/*
Input: num = 16
Output: true
*/

int main(){
    int n;
    cin >> n; 
    cout<< isPerfectSquare(n);
}
