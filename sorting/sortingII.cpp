#include<bits/stdc++.h>
using namespace std;

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

void mergeSort(vector<int> &arr, int low, int high){
    if(low == high) return;
    int mid = (low + high)/ 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
}


//recursive bubble sort
void recbub(vector<int> &arr, int n){
    if(n == 1) return;
    for(int j = 0; j <= n-2; j++){
        if(arr[j] > arr[j+1]){
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
        }
    }
    recbub(arr, n-1);
}

// void recins(vector<int> arr){
//     int min = 0;
//     recins(arr);
//     for(int i = 0; i < arr.size(); i++){
//         if(min > arr[i]){
//             min = arr[i];
//             int temp = arr[i];
//             arr[i] = arr[]
//         }
        
//     }
//     if(min == 0) return;
// }

//quicksort
int partitionF(vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i < j){
        while(arr[i] <= pivot && i <= high){
            i++;
        }
        while(arr[j] > pivot && j >= low){
            j--;
        }
        if(i < j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}


void quickSort(vector<int> &arr, int low, int high){
    if(low < high){
        int partition = partitionF(arr, low, high);
        quickSort(arr, low, partition-1);
        quickSort(arr, partition+1, high);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    //mergeSort(arr, 0, n-1);
    //recbub(arr, n);
    quickSort(arr, 0, n-1);
    for(auto a : arr){
        cout << a << " ";
    }

}