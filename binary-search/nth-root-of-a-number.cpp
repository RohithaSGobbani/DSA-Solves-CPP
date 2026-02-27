#include<bits/stdc++.h>
using namespace std;

int power(int a, int b, int n){
    if(n == 0) return 1;
    int ans = power(a,b,n-1) * a;  
    return ans;
}

//Brute:LS
int nthroot(int n, int m){
    for(int i = 1; i < m; i++){
       if(power(i,n,n) == m) return i;
       else if(power(i,n,n) > m) break;
    }
    return -1;
}

//Optimal: BS
int nthrootbs(int n,int m){
    int low = 1, high = m;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(power(mid,n,n) == m){
            return mid;
        }else if(power(mid,n,n) > m){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return -1;
}

/*
Input: N = 3, M = 27
Output: 3
Explanation: The cube root of 27 is equal to 3.
*/

int main(){
    int m,n;
    cin >> n>> m;
    cout << nthrootbs(n,m);
}