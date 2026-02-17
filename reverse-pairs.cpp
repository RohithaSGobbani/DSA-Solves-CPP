#include<bits/stdc++.h>
using namespace std;

//Brute
void reversepairBrute(vector<int> &arr){
    int n = arr.size();
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i] > 2 * arr[j]){
                cnt++;
            }
        }
    }
    cout << cnt;
}

//Optimal
//merge sort
void merge(vector<int> &arr, int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left <= mid){
        temp.push_back(arr[left]);
        left++;        
    }
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i = low; i <= high; i++){
        arr[i] = temp[i - low];
    }
}

int coutPairs(vector<int> &arr, int low, int mid, int high){
    int right = mid+1;
    int cnt = 0;
    for(int i = low; i <= mid; i++){
        while(right <= high && arr[i] > 2*arr[right]){
            right++;
        }  
        cnt += (right - (mid+1));
        
    }
    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high){
    int cnt = 0;
    if(low >= high) return cnt;
    int mid = (low + high)/ 2;
    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid+1, high);
    cnt += coutPairs(arr,low, mid, high);
    merge(arr, low, mid, high);
    return cnt;
}

int reversepairOptimal(vector<int> &arr){
    return mergeSort(arr, 0 , arr.size()-1);
}

/*
Input: 40 25 19 12 9 6 2
Output: 15
*/

int main(){
    int n; 
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << reversepairOptimal(arr);
}