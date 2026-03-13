#include<bits/stdc++.h>
using namespace std;

int lb(vector<int> &arr, int k){
  int n = arr.size();
  int low = 0, high = n-1;
  while(low <= high){
      int mid = low + (high - low)/2;
      if(arr[mid] >= k){
          high = mid-1;
      }else{
          low = mid + 1;
      }
  }
  return low;
}
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    int cntmax = 0;
    int ind = -1;
    for(int i = 0; i < n; i++){
        int cnt_ones = m - lb(matrix[i],1);
        if(cnt_ones > cntmax){
            cntmax = cnt_ones;
            ind = i;
        }
    }
    return ind;
}

/*
Input : mat = [ [1, 1, 1], [0, 0, 1], [0, 0, 0] ]
Output: 0
*/

int main(){
    vector<vector<int>> mat = {{1,1,1},{0,0,1},{0,0,0}};
    cout << rowWithMax1s(mat, 3,3);
    return 0;
}