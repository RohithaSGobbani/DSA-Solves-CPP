#include<bits/stdc++.h>
using namespace std;

int maxEle(vector<vector<int>> &mat, int n, int m, int col){
    int maxValue = -1;
    int index = -1;
    for(int i = 0; i < n; i++){
        if(mat[i][col] > maxValue){
            maxValue = mat[i][col];
            index = i;
        }
    }
    return index;
}
vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    int low = 0, high = m-1;
    while(low <= high){
        int mid = low + (high - low)/2;
        int row = maxEle(mat,n,m,mid);
        int left = mid-1 >= 0 ? mat[row][mid-1] : -1;
        int right = mid+1 < m ? mat[row][mid+1] : -1;
        if(mat[row][mid] > left && mat[row][mid] > right){
            return {row,mid};
        }else if(mat[row][left] < left) high = mid-1;
        else low = mid+1;
    }
    return {-1,-1};
}

/*
Input: mat = [[1,4],[3,2]]
Output: [0,1]
*/

int main(){
    vector<vector<int>> mat = {{1,4},{3,2}};
    vector<int> ans = findPeakGrid(mat);
    for(auto &a:ans){
        cout << a << " ";
    }
    return 0;
}