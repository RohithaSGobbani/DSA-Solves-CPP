#include<bits/stdc++.h>
using namespace std;

//Brute
int findMedianBrute(vector<vector<int>> &mat){
    vector<int> ls;
    int n = mat.size();
    int m = mat[0].size();    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            ls.push_back(mat[i][j]);
        }
    }
    sort(ls.begin(),ls.end());
    return ls[(n*m)/2];
}

//BS
int ub(vector<int> &arr, int x){
    int n = arr.size();
    int low = 0, high = n-1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] > x) high = mid-1;
        else low = mid + 1;
    }
    return low;
}

int countSmallEqual(vector<vector<int>> &matrix, int n, int m, int x){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        cnt += ub(matrix[i], x);
    }
    return cnt;
}

int findMedian(vector<vector<int>>&matrix) {
    int low = INT_MAX, high = INT_MIN;
    int n = matrix.size();
    int m = matrix[0].size();
    for(int i = 0; i < n; i++){
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][m-1]);
    }
    int req = (n*m)/2;
    while(low <= high){
        int mid = low + (high - low)/2;
        int smallEqual = countSmallEqual(matrix,n,m,mid);
        if(smallEqual <= req) low = mid+1;
        else high = mid-1;
    }
    return low;
}

/*
Input: matrix=[ [1, 4, 9], [2, 5, 6], [3, 7, 8] ] 
Output: 5
Explanation: If we find the linear sorted array, the array becomes 1 2 3 4 5 6 7 8 9. So, median = 5
*/

int main(){
    vector<vector<int>> mat = {{1, 4, 9}, {2, 5, 6}, {3, 7, 8}};
    cout << findMedianBrute(mat);
    return 0;
}