#include<bits/stdc++.h>
using namespace std;

//Brute
void maxproductBrute(vector<int> &arr){
    int n = arr.size();
    int maxi = INT_MIN;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int prod = 1;
            for(int k = i; k <= j; k++){
                prod *= arr[k];
            }
            maxi = max(maxi, prod);
        }
    }
    cout << maxi;
}

//Better
void maxproductBetter(vector<int> &arr){
    int n = arr.size();
    int maxi = INT_MIN;
    for(int i = 0; i < n; i++){
        int prod = 1;
        for(int j = i; j < n; j++){
            prod *= arr[j];
            maxi = max(maxi, prod);
        }
    }
    cout << maxi;
}

//Optimal
void maxproductOptimal(vector<int> &arr){
    int n = arr.size();
    int pref = 1, suff =1;
    int maxi = INT_MIN;
    for(int i = 0; i < n; i++){
        if(pref == 0) pref = 1;
        if(suff == 0) suff = 1;
        pref = pref * arr[i];
        suff = suff * arr[n-i-1];
        maxi = max(maxi , max(pref, suff));
    }
    cout << maxi;
}

/*
Input : 2 3 -2 4
Output : 6
*/

int main(){
    int n; 
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    maxproductOptimal(arr);
}