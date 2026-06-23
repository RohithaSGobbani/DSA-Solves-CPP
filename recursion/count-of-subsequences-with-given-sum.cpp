#include<bits/stdc++.h>

using namespace std;

void countS(int i, int n, const vector<int> &arr, int s, int &count, int sum){
    if(i == n){
        if(sum == s){
            count++;
            return;
        }
        return;
    }
    sum += arr[i];
    countS(i + 1, n, arr, s, count, sum);
    sum -= arr[i];
    countS(i + 1, n, arr, s, count, sum);
}

bool printOnlyOne(int i, int n, const vector<int> &arr, int s, int &count, int sum){
    if(i == n){
        if(sum == s){
            count++;
            return true;
        }
        return false;
    }
    sum += arr[i];
    if(printOnlyOne(i + 1, n, arr, s, count, sum) == true) return true;
    sum -= arr[i];
    if(printOnlyOne(i + 1, n, arr, s, count, sum) == true) return true;
    return false;
}

int countSubsequences(int n, const vector<int>& arr, int s) {
    // Write your code here
    int count = 0;
    countS(0, n, arr, s, count, 0);
    return count;
}

int main(){
    const vector<int> arr = {1,2,1};
    int s = 2;
    int count = 0;
    bool c = printOnlyOne(0, arr.size(), arr, s, count, 0);
    if(c) cout << count;
    return 0;
}
