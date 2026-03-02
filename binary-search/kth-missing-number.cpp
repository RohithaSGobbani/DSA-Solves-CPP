#include<bits/stdc++.h>
using namespace std;

//Brute
int missing(vector<int> &arr, int k){
    int n = arr.size();
    for(int i = 0; i < n; i++){
        if(arr[i] < k) k++;
        else break;
    }
    return k;
}

//Optimal : BS
int missingbs(vector<int> &arr, int k){
    int n = arr.size();
    int low = 0, high = n-1;
    while(low <= high){
        int mid = low + (high - low)/2;
        int missing = arr[mid] - (mid + 1);
        if(missing < k) low = mid+1;
        else high = mid-1;
    }
    cout << low << " " << high << endl;
    return low+k;
}

int main(){
    int n;
    cin >> n; 
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int k;
    cin >> k;
    cout << missingbs(arr, k);
}