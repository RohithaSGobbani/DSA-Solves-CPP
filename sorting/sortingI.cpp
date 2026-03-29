#include <bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n){
        for(int i = 0; i < n-1; i++){
        int min, temp;
        min = i;
        for(int j = i; j < n; j++){
        if(arr[j] < arr[min]){
            min = j;
        }
        }
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
    
    for(int i = 0; i < n; i++){
        cout << arr[i] << endl;
    }
}

void bubble_sort(int arr[], int n){
    for(int i = n-1; i >= 0; i--){
        int swapped = 0;
        for(int j = 0; j <= i-1; j++){
            if(arr[j]> arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;
            }
        }
        if(swapped == 0){
            break;
        }
    }
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}

void insertion_sort(int arr[], int n){
    for(int i = 0; i < n; i++){
        int j = i;
        while(j > 0 && arr[j-1] > arr[j]){
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
                j--;
        }
    }
        for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    //selection_sort(arr, n);
    insertion_sort(arr, n);
    return 0;
}
