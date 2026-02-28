#include<bits/stdc++.h>
using namespace std;

int mini(vector<int> &arr){
    int n = arr.size();
    int mini = INT_MAX;
    for(int i = 0; i < n; i++){
        mini = min(mini, arr[i]);
    }
    return mini;
}

int maxi(vector<int> &arr){
    int n = arr.size();
    int maxi = INT_MIN;
    for(int i = 0; i < n; i++){
        maxi = max(maxi, arr[i]);
    }
    return maxi;
}

bool possible(vector<int> &arr, int day, int m, int k){
    int cnt = 0, nob = 0;
    int n = arr.size();
    for(int i = 0; i < n; i++){
        if(arr[i] <= day){
            cnt++;
        }else{
            nob += (cnt/k);
            cnt = 0;
        }
    }
    nob += (cnt/k);
    if(nob >= m) return true;
    else return false;
}

//Brute
int minDays(vector<int> &arr, int m, int k){
    for(int i = mini(arr); i <= maxi(arr); i++){
        if(possible(arr,i,m,k) == true){
            return i;
        }
    }
}

//BS
int minDaysbs(vector<int> &arr,int m, int k){
    int n = arr.size();
    if(n < (long long)m*k) return -1;
    int low = mini(arr), high = maxi(arr);
    while(low <= high){
        int mid = low + (high - low)/2;
        if(possible(arr,mid,m,k) == true){
            high = mid - 1;
        }
        else{
            low = mid+1;
        }
    }        
    return low;
}

/*
Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
Output: 3
*/

int main(){
    int n,m,k;
    cin >> n; 
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cin >> m >>k;
    cout << minDays(arr,m,k);
}