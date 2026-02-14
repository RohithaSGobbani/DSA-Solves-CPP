#include<bits/stdc++.h>
using namespace std;

//Brute
void cntinversionsBrute(vector<int> &arr){
    int n = arr.size();
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i] > arr[j]){
                cnt++;
            }
        }
    }
    cout << cnt;
}

//Optimal : Using Merge sort
int merge(vector<int> &arr, int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    int cnt = 0;    
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            cnt += (mid - left + 1);
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
    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high){
    int cnt = 0;
    if(low == high) return cnt;
    int mid = (low + high)/ 2;
    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid+1, high);
    cnt += merge(arr, low, mid, high);
    return cnt;
}

void cntinversionsOptimal(vector<int> &arr){
    cout << mergeSort(arr, 0, arr.size()-1);
}

/*int cnt = 0;
Input : 5 3 2 4 1
Output : 8
*/

int main(){
    int n; 
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cntinversionsOptimal(arr);
}