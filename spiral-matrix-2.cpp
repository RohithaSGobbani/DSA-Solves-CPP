#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n));
        int top = 0, bottom = n-1;
        int left = 0, right = n-1;
        int num = 1;
        while(top <= bottom && left <= right){
            for(int i = left; i <= right; i++){
                mat[top][i] = num;                
                num+=1;
            }
            top++;
            for(int i = top; i <= bottom; i++){
                mat[i][right] = num;                
                num+=1;
            }
            right--;
            if(top <= bottom){
                for(int i = right; i >= left; i--){
                    mat[bottom][i] = num;
                    num+=1;
                }
                bottom--;
            }
            if(left <= right){
                for(int i = bottom; i >= top; i--){
                    mat[i][left] = num;
                    num+=1;
                }
                left++;
            }
        }
        return mat;
    }
};
    int main(){
        Solution obj;
        int n;
        cin >>  n;
        vector<vector<int>> result = obj.generateMatrix(n);
        for (auto &row : result) {
            for (int x : row) {
                cout << x << " ";
            }
            cout << "\n";
        }        
        return 0;
    }

/*
Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]
*/