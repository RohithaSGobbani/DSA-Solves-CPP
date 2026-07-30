#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<vector<int>> &board){
    for(int i = 0; i < row; i++){
        if(board[i][col]) return false;
    }
    for(int i = row-1, j = col-1; i >= 0 && j>= 0; i--, j--){
        if(board[i][j]) return false;
    }
    for(int i = row-1, j = col+1; i >= 0 && j< board.size(); i--, j++){
        if(board[i][j]) return false;
    }
    return true;
}
void solve(int row, int n, vector<vector<string>> &ans,vector<vector<int>> &board){
    if(row == n){
        vector<string> r;
        for(int i = 0; i < n; i++){
            string s;
            for(int j = 0; j < n; j++){
                s += board[i][j] ? 'Q' : '.';
            }
            r.push_back(s);
        }
        ans.push_back(r);
    }
    for(int col = 0; col < n; col++){
        if(isSafe(row,col,board)){
            board[row][col] = 1;
            solve(row+1,n,ans,board);
            board[row][col] = 0;
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<vector<int>> board(n,vector<int>(n,0));
    solve(0, n, ans, board);
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<vector<string>> queens = solveNQueens(n);
    for (const auto& row : queens) {       // Access each row by reference
        for (const auto &element : row) {          // Access each element in that row
            cout << element << " " << endl;
        }
        cout << "\n";                 // Newline at the end of each row
    }
    return 0;
}