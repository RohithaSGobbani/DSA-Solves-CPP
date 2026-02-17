#include<bits/stdc++.h>
using namespace std;

void largestInArray(int arr[], int n){
        int largest = arr[0];
    for(int i = 1 ; i < n; i++){
        if(arr[i] > largest){
            largest = arr[i];
        }
    }
    cout << largest << endl; // O(N)
}

void seclargest(int arr[], int n){
    int largest = arr[0], slargest = INT_MIN;
    for(int i = 1; i < n; i++){
        if(arr[i] > largest){
            slargest = largest;
            largest = arr[i];
        }
        if(arr[i] > slargest && arr[i] != largest){
            slargest = arr[i];
        }
    }
    cout << slargest << endl; // O(N)
}

void numberofunique(int arr[], int n){
    int i = 0;
    for(int j = 1; j < n; j++){
        if(arr[j] != arr[i]){
            arr[i+1] = arr[j];
            i++;
        }
    }
    cout << "No. of unique elements are: " << i+1 << endl;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    largestInArray(arr, n);
    seclargest(arr, n);
    numberofunique(arr, n);
}