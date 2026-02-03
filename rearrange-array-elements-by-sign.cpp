#include<bits/stdc++.h>
using namespace std;

void rearrangesignBrute(vector<int> &arr){
    int n = arr.size();
    vector<int> pos;
    vector<int> neg;
    for(int i = 0; i < n; i++){
        if(arr[i] < 0){
            neg.push_back(arr[i]);
        }else if(arr[i] > 0){
            pos.push_back(arr[i]);
        }
    }
    for(int i = 0; i < n/2; i++){
        arr[2*i] = pos[i];
        arr[2*i+1] = neg[i];
    }
    for(auto a: arr){
        cout << a << " ";
    }
}

void rearrangesignBetter(vector<int> &arr){
    int n = arr.size();
    vector<int> arr1(n);
    int posIndex = 0;
    int negIndex = 1;
    for(int i = 0; i < n; i++){
        if(arr[i] < 0){
            arr1[negIndex] = arr[i];
            negIndex += 2;
        }else{
            arr1[posIndex] = arr[i];
            posIndex += 2;
        }
    }
    for(auto a: arr1){
        cout << a << " ";
    }
}

//Variety: no. of -ves != +ves
void rearrangesign(vector<int> &arr){
    int n = arr.size();
    vector<int> pos,neg;
    for(int i = 0; i < n; i++){
        if(arr[i] < 0){
            neg.push_back(arr[i]);
        }else{
            pos.push_back(arr[i]);
        }
    }
    if(pos.size() > neg.size()){
        for(int i = 0; i < neg.size(); i++){
            arr[2*i] = pos[i];
            arr[2*i+1] = neg[i];
        }
        int index = 2*neg.size();
        for(int i = neg.size(); i < pos.size(); i++){
            arr[index] = pos[i];
            index++;
        }
    }else{
        for(int i = 0; i < pos.size(); i++){
            arr[2*i] = pos[i];
            arr[2*i+1] = neg[i];
        }
        int index = 2*pos.size();
        for(int i = pos.size(); i < neg.size(); i++){
            arr[index] = neg[i];
            index++;
        }
    }
    for(auto a: arr){
        cout << a<< " ";
    }
}

"""
Input: nums = [3,1,-2,-5,2,-4]
Output: [3,-2,1,-5,2,-4]
"""

int main(){
    int n; 
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    //rearrangesignBetter(arr);
    rearrangesign(arr);
    return 0;
}