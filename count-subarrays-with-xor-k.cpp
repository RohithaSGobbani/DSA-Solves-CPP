#include<bits/stdc++.h>
using namespace std;

//Brute
void cntsubarrayxorBrute(vector<int> &arr, int k){
    int n = arr.size();
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int x = 0;
            for(int k = i; k <=j; k++){
                x = x ^ arr[k];                
            }
            if(x == k){
                cnt++;
            }            
        }
    }
    cout << cnt ;
}

//Better
void cntsubarrayxorBetter(vector<int> &arr, int k){
    int n = arr.size();
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int x = 0;
        for(int j = i; j < n; j++){
            x = x ^ arr[j];
            if(x == k){
                cnt++;
            }            
        }
    }
    cout << cnt ;
}

//Optimal
void cntsubarrayxorOptimal(vector<int> &arr, int k){
    int n = arr.size();
    int cnt = 0;
    unordered_map<int,int> mpp;
    mpp[0] = 1;
    int xr = 0;
    for(int i = 0; i < n; i++){
        xr = xr ^ arr[i];
        int x = xr ^ k;
        cnt += mpp[x];
        mpp[xr] += 1;
    }
    cout << cnt;
}

/*
Input: A = [4, 2, 2, 6, 4] , k = 6
Output: 4
*/

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cntsubarrayxorOptimal(arr, 6);
}