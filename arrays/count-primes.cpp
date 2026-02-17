#include<bits/stdc++.h>
using namespace std;

int countPrimes(int n) {
    vector<bool> isPrime(n+1, true);
    int cnt = 0;
    for(int i = 2; i < n; i++){
        if(isPrime[i]){
            cnt++;
        }
        for(int j = i*2; j < n; j = j+i){
            isPrime[j] = false;
        }
    }
    return cnt;
}

int main(){
    int n; 
    cin >> n;
    cout << countPrimes(n);
    return 0;
}