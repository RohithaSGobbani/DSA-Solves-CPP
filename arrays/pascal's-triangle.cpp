#include<bits/stdc++.h>
using namespace std;

//!.Given row r and column c , return the element ar r and c
//R-1Cc-1
int ncr(int n, int r){
    int ans =1;
    for(int i = 0; i < r; i++){
        ans = ans * (n-i);
        ans = ans / (i+1);
    }
    return ans;
}

/*
Input: r = 5, c= 3
Output: 6
*/

//2.Given n , print the nth row of pascal's traingale
void rowP(int n){
    int ans = 1;
    vector<int> ansV;
    ansV.push_back(ans);
    for(int i = 1; i < n; i++){
        ans = ans * (n - i);
        ans = ans / i;
        ansV.push_back(ans);
    }
    for(auto a: ansV){
        cout << a << " ";
    }
}
/*
Input: 5
Output: 1 4 6 4 1
*/

//3.Print Entire triangle given n
vector<int> pas(vector<int> &arr){
    int n = arr.size();
    vector<int> nextRow;
    nextRow.push_back(1);
    for(int i = 0; i < n-1; i++){
        nextRow.push_back(arr[i]+arr[i+1]);
    }
    nextRow.push_back(1);
    // for(auto a: nextRow){
    //     cout << a << " ";
    // }
    return nextRow;
}

void pas1(int n){
    vector<vector<int>> ans;
    ans.push_back({1});
    for(int i = 0; i < n-1; i++){
        ans.push_back(pas(ans[i]));
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

/*
Input: n = 5
Output: [[1],[1 1],[1 2 1],[1 3 3 1],[1 4 6 4 1]]
*/

int main(){
    int n; 
    cin >> n;
    vector<int> arr(n);
    // for(int i = 0; i < n; i++){
    //     cin >> arr[i];
    // }
    rowP(n);
    return 0;
}