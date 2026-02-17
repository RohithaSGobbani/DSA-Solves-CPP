#include<bits/stdc++.h>
using namespace std;

void longestBrute(vector<int> &arr){
    int n = arr.size();
    int mx = 0;
    for(int i = 0; i < n; i++){
        int sum = arr[i];
        for(int j = i+1; j < n; j++){
            sum += arr[j];
            if(sum == 0){
                mx = max(mx, j - i + 1);
            }
        }
    }
    cout << mx;
}

void longestOptimal(vector<int> &arr){
    int n = arr.size();
    int mx = 0;
    int sum = 0;
    unordered_map<int,int> mp;
    for(int i = 0; i < n; i++){
        sum += arr[i];

        if(sum == 0){
            mx = i + 1;
        }
        else{
            if(mp.find(sum) != mp.end()){
                mx = max(mx, i - mp[sum]);
            }
            else{
                mp[sum] = i;
            }
        }
    }
    cout << mx;
}

/*
Input:
 N = 6, array[] = {9, -3, 3, -1, 6, -5}  
Result:
 5  
*/

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    longestOptimal(arr);
}