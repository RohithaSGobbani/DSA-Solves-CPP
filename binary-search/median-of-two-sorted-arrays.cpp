#include<bits/stdc++.h>
using namespace std;

//Brute
int medianBrute(vector<int> &arr1, vector<int> &arr2){
    int n1 = arr1.size();
    int n2 = arr2.size();
    vector<int> arr3;
    int i = 0, j = 0;
    while(i < n1 && j < n2){
        if(arr1[i] < arr2[j]) arr3.push_back(arr1[i++]);
        else arr3.push_back(arr2[j++]);
    }
    while(i < n1) arr3.push_back(arr1[i++]);
    while(j < n2) arr3.push_back(arr2[j++]);
    int n = arr3.size();
    if(n % 2 == 1) return arr3[n/2];
    else return (arr3[n/2] + arr3[(n/2)-1])/2;
}

int main(){
    int n1, n2;
    cin >> n1 >> n2;
    vector<int> arr1(n1);
    for(int i = 0; i < n1; i++){
        cin >> arr1[i];
    }
    vector<int> arr2(n2);
    for(int i = 0; i < n2; i++){
        cin >> arr2[i];
    }
    cout<< medianBrute(arr1, arr2);
    return 0;
}