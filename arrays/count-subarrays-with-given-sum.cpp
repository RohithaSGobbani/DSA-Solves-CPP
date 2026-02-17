#include<bits/stdc++.h>
using namespace std;

//Brute
void subarraysSumK(vector<int> &arr, int k){
    int n = arr.size();
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int sum = 0;            
            for(int k = i; k <=j; k++){
                sum += arr[k];
            }
            if(sum == k) cnt++;
        }
    }
    cout << cnt;
}

//Better
void subarraysSumKBetter(vector<int> &arr, int k){
    int n = arr.size();
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int sum = 0;        
        for(int j = i; j < n; j++){
            sum += arr[j];
            if(sum == k) cnt++;
        }
    }
    cout << cnt;
}

//Optimal
void subarraysSumKOptimal(vector<int> &arr, int k){
    int n = arr.size();
    int cnt = 0, prefix = 0;
    unordered_map<int,int> mpp;
    mpp[0] = 1;
    for(int i = 0; i < n; i++){
        prefix += arr[i];
        int remove = prefix - k;
        cnt += mpp[remove];
        mpp[prefix] += 1;
    }
    cout << cnt;
}

/*
Input : N = 4, array[] = {3, 1, 2, 4}, k = 6
Output: 2
*/

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    subarraysSumKOptimal(arr, 3);
    return 0;
}