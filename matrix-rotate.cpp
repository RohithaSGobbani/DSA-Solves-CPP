#include<bits/stdc++.h>
using namespace std;

//Brute
void matrixrotateBrute(vector<vector<int>> &arr){
    int n = arr.size();
    vector<vector<int>> ans(n,vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ans[j][(n-1-i)] = arr[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }      
}

void matrixrotateOptimal(vector<vector<int>> &arr){
    int n = arr.size();
    //Transpose
    for(int i = 0; i <= n-2; i++){
        for(int j = i+1; j <= n-1; j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
    //Reverse every array
    for(int i = 0; i < n; i++){
        reverse(arr[i].begin(), arr[i].end());
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }        
}

/*
Input :matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
Output :matrix = [[7, 4, 1], [8, 5, 2], [9, 6, 3]]
*/

int main(){
    int m,n;
    cin >> m >> n;
    vector<vector<int>> arr(m, vector<int> (n));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    matrixrotateOptimal(arr);
    return 0;
}