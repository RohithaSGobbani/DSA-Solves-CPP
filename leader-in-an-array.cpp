#include <bits/stdc++.h>
using namespace std;

void leaderBrute(vector<int> &arr){
    int n = arr.size();
    vector<int> ans;
    for(int i = 0; i < n; i++){
        bool leader = true;
        for(int j = i+1; j < n; j++){
            if(arr[j] > arr[i]){
                leader = false;
                break;
            }
        }
        if(leader)
        ans.push_back(arr[i]);
    }
    for(auto a: ans){
        cout << a << " ";
    }
}

void leaderOptimal(vector<int> &arr){
    int n = arr.size();
    vector<int> ans;
    int maxi = INT_MIN;
    for(int i = n-1; i >= 0; i--){
        if(arr[i] > maxi){
            ans.push_back(arr[i]);
        }
        maxi = max(arr[i], maxi);
    }
    reverse(ans.begin(), ans.end());
    for(auto a: ans){
        cout << a << " ";
    }
}

/*
Input:
 arr = [4, 7, 1, 0]  
Output:
 7 1 0  
*/

int main(){
    int n; 
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    leaderOptimal(arr);
    return 0;    
}