#include<bits/stdc++.h>
using namespace std;


int totalhr(vector<int> &arr, int hourly){
    int totalhrs = 0;
    int n = arr.size();
    for(int i = 0; i < n; i++){
        totalhrs += (arr[i] + hourly - 1)/hourly;
    }
    return totalhrs;
}

int maxi(vector<int> &arr){
    int n = arr.size();
    int maxi = INT_MIN;
    for(int i = 0; i < n; i++){
        maxi = max(maxi,arr[i]);
    }
    return maxi;
}
//Brute
int minEatingSpeed(vector<int> &arr, int h){
    // int n = arr.size();
    for(int i = 1; i <= maxi(arr); i++){
        int reqtime = totalhr(arr,i);
        if(reqtime <= h){
            return i;
        }
    }
}

//Optimal: BS
int minEatingSpeedBS(vector<int> &arr, int h){
    int low = 0, high = maxi(arr);
    while(low <= high){
        int mid = low + (high - low)/2;
        int totalhrs = totalhr(arr,mid);
        if(totalhrs <= h){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return low;
}

/*
Input: piles = [3,6,7,11], h = 8
Output: 4
*/

int main(){
    int n;
    cin >> n; 
    vector<int> arr(n);
    int h;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cin >> h;
    cout << minEatingSpeedBS(arr,h);
}