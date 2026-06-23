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

int countSubsequences(int n, const vector<int>& arr, int s) {
    // Write your code here
    int count = 0;
    countS(0, n, arr, s, count, 0);
    return count;
}

int main(){
    const vector<int> arr = {1,2,1};
    int s = 2;
    int count = countSubsequences(arr.size(), arr, s);
    cout << count;
    return 0;
}
