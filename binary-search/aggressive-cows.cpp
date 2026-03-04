#include<bits/stdc++.h>
using namespace std;

bool canweplace(vector<int> &arr, int dist, int cows){
    int cntcows = 1, last = arr[0];
    int n = arr.size();
    for(int i = 1; i < n; i++){
        if(arr[i] - last >= dist){
            cntcows++;
            last = arr[i];
        }
    }
    if(cntcows >= cows) return true;
    else return false;
}

//Brute
int max_distance_in_min(vector<int> &arr, int cows){
    sort(arr.begin(),arr.end());
    int maxi = *max_element(arr.begin(),arr.end());
    int mini = *min_element(arr.begin(),arr.end());
    for(int i = 1; i < maxi - mini; i++){
        if(canweplace(arr,i,cows) == true){
            continue;
        }else{
            return (i-1);
        }
    }
    return -1;
}

//Optimal
int max_distance_in_minBS(vector<int> &arr, int cows){
    sort(arr.begin(),arr.end());
    int high = *max_element(arr.begin(),arr.end());
    int low = *min_element(arr.begin(),arr.end());
    while(low <= high){
        int mid = low + (high - low)/2;
        if(canweplace(arr,mid,cows) == true){
            low = mid+1;
        }else{
            high = mid - 1;
        }
    }
    return high;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int cows;
    cin >> cows;
    cout << max_distance_in_minBS(arr,cows);
}