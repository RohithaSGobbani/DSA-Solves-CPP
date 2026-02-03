#include<bits/stdc++.h>
using namespace std;

void nextPermu(vector<int> &arr){
    int n = arr.size(), index = -1;
    for(int i = n-2; i >= 0; i--){
        if(arr[i] < arr[i+1]){
            index = i;
            break;
        }
    }
    if(index == -1){
        reverse(arr.begin(), arr.end());
    }
    for(int i = n-1; i >= index; i--){
        if(arr[i] > arr[index]){
            swap(arr[i], arr[index]);
            break;
        }
    }
    sort(arr.begin() + index+1, arr.end());
    for(auto a: arr){
        cout << a << " ";
    }
}

"""
Input: nums = [1,2,3]
Output: [1,3,2]
"""

int main(){
    int n; 
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }    
    nextPermu(arr);
    return 0;
}