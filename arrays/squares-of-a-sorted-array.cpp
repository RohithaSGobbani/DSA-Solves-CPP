#include<bits/stdc++.h>
using namespace std;

void sortedSquares(vector<int>& arr) {
    vector<int> ans;
    int n = arr.size();
    for(int i = 0; i < n; i++){
        ans.push_back(arr[i]*arr[i]);
    }
    sort(ans.begin(),ans.end());
    for(auto a: ans){
        cout << a << " ";
    }
}

/*
Input : 9 -3 3 -1 6 -5
Output : 1 9 9 25 36 81 
*/

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sortedSquares(arr);
}