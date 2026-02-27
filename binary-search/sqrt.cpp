#include<bits/stdc++.h>
using namespace std;

//Brute: LS way
int sqrt(int n){
    int ans = 1;
    for(int i = 1; i <= n; i++){
        if(i*i <= n){
            ans = i;
        }else{
            break;
        }
    }
    return ans;
}

int sqrtbs(int n){
    int low = 1, high = n;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(mid*mid > n){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return high;
}

/*
Input : 36
Output: 6
*/

int main(){
    int n;
    cin >> n;
    cout << sqrtbs(n);
}