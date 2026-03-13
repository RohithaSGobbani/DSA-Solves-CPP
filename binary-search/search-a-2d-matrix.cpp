#include<bits/stdc++.h>
using namespace std;

//Better
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    for(int i = 0; i < n; i++){
        int low = 0, high = m-1;            
        while(low <= high){
            int mid = low + (high - low)/2;
            if(matrix[i][mid] == target){
                return true;
            }else if(matrix[i][mid] > target){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }            
    }
    return false;
}

//Optimal
bool searchMatrixOptimal(vector<vector<int>>& matrix, int target) {
    int m = matrix[0].size();
    int n = matrix.size();
    int low = 0, high = n*m-1;
    while(low <= high){
        int mid = low + (high - low)/2;
        int row = mid/m , col = mid % m;
        if(matrix[row][col] == target){
            return true;
        }else if(matrix[row][col] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

/*
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
*/

int main(){
    vector<vector<int>> mat = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 3;
    cout << searchMatrixOptimal(mat, target);
    return 0;
}