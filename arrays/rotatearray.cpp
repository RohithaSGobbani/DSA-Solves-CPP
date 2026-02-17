#include<bits/stdc++.h>
using namespace std;

void leftshiftbyOne(int arr[], int n){
    int temp = arr[0];
    for(int i = 1; i < n; i++){
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}

//Brute
void leftshiftbyD(int arr[], int n, int d){

    d = d % n;
    int temp[d];

    for(int i = 0; i < d; i++){
        temp[i] = arr[i];
    }

    for(int i = d; i < n; i++){
        arr[i-d] = arr[i];
    }

    for(int i = n-d; i < n; i++){
        arr[i] = temp[i-(n-d)];
    }
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}

//optimal
void leftshiftbyOptimal(int arr[], int n, int d){
    reverse(arr, arr+d);
    reverse(arr+d, arr+n);
    reverse(arr, arr+n);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}

/*
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
*/

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    //leftshiftbyOne(arr, n);
    leftshiftbyOptimal(arr, n, 3);
    return 0;
}
