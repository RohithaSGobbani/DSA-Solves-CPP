#include <bits/stdc++.h>
using namespace std;

//There are 2 varities of this question
//1.Target is possible or not
//2.Returning the indices that add up to target

//brute
void twosumbrute(vector<int> &arr, int tar){
    int n = arr.size();
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] + arr[j] == tar){
                cout << i << " " << j;
            }
        }
    }
}

//better : hashing
void twosumbetter(vector<int> &arr, int tar){
    int n = arr.size();
    map<int, int> mpp;
    for(int i = 0; i < n; i++){
        if(mpp.find(tar - arr[i]) != mpp.end()){
            cout << i << " " << mpp[tar - arr[i]];
        }
        if(mpp.find(arr[i]) == mpp.end()){
            mpp[arr[i]] = i;
        }
    }
}

//optimal : 2 pointer approach
string twosumoptimal(vector<int> &arr, int tar){
    int left = 0;
    int n = arr.size();
    int right = n-1;
    sort(arr.begin(), arr.end());
    while(left < right){
        int sum = arr[left] + arr[right];
        if(sum == tar){
            //cout << left << " " << right;
            //not possible for returning indices, only for true or false
            
            return "True";
        }else if(sum < tar){
            left++;
        }else{
            right--;
        }
    }
    return "False";
}

"""
Input: arr = [2,6,5,8,11], tar = 14
Output: true
"""

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    //twosumbrute(arr, 14);
    //twosumbetter(arr, 14);
    cout << twosumoptimal(arr, 14);
    return 0;
}