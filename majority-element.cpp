#include <bits/stdc++.h>
using namespace std;

int majorityBetter(vector<int> &arr){
    int n = arr.size();
    unordered_map<int, int> mpp;
    for(int i = 0; i < n; i++){
        mpp[arr[i]]++;
    }
    for(int i = 0; i < n; i++){
        if(mpp[arr[i]] > (n/2)){
            return arr[i];
        }
    }
    return -1;
}

//Moore's voting algorithm
int majorityOptimal(vector<int> &arr){
    int n = arr.size();
    int ele;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(cnt == 0){
            ele = arr[i];
            cnt = 1;
        }
        else if(arr[i] == ele){
            cnt++;
        }else{
            cnt--;
        }
    }
    int cnt1 = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == ele) cnt1++;
    }
    if(cnt1 > (n/2)) return ele;

    return -1;
}

void mostFrequentEven(vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, int> mpp;
    for(int i = 0; i < n; i++){
        if(arr[i] % 2 == 0){
            mpp[arr[i]]++;
        }
    }
    //if(mpp.empty()) return -1;
    int maxfreq = mpp[0];
    for(int i = 0; i < n; i++){
        if(maxfreq < mpp[i]){
            maxfreq = mpp[i];
        }
    }
    int a = mpp[arr[0]];
    for(int i = 0; i < n; i++){
        if(maxfreq == mpp[arr[i]]){
            a = min(a, arr[i]);
        }
    }
    cout << a;
    //return mini;
}

"""
Input: arr = [2,2,3,3,1,2,2]
Output: 2
"""

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    //cout << majorityBetter(arr);
    //cout << majorityOptimal(arr);
    mostFrequentEven(arr);
}