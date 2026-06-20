#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
long long power(long long x, long long n){
    if(n == 0) return 1;
    x = x % MOD;
    if(n % 2 == 0){
        return power((x * x) % MOD, n / 2);
    }else{
        return x * power(x, n - 1) % MOD;
    }
}

int countGoodNumbers(long long n) {
    long long e = (n+1)/2;
    long long p = (n)/2;
    long long e_ways = power(5, e);
    long long p_ways = power(4, p);
    return (e_ways * p_ways) % MOD;
}

int main(){
    long long n;
    cin >> n;
    cout << countGoodNumbers(n);
    return 0;
}