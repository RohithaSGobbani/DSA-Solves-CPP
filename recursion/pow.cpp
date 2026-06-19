#include<bits/stdc++.h>
using namespace std;

double helper(double x, long long n) {
    if(n == 0) return 1.0;
    if(n == 1) return x;
    if(n % 2 == 0){
        return helper(x*x, n/2);
    }
    return x * helper(x, n - 1);
}

double myPow(double x, int n) {
    int m = n;
    if(m < 0){
        return (1.0 / helper(x, ((long long)-1 * m)));
    }
    return helper(x, m);
}

int main(){
    double x;
    int n;
    cin >> x >> n;
    cout << myPow(x, n);
    return 0;
}