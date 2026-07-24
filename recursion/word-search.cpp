#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(int i, int j, int idx, vector<vector<char>> &board, string &word, string &s, vector<vector<bool>> &visited) {
        if(s.length() == word.length()){
            return s==word;
        }

        //Down
        if(i+1 < board.size() && board[i+1][j] == word[idx] && visited[i+1][j] == false){
            s += board[i+1][j];
            visited[i+1][j] = true;
            if(solve(i+1, j, idx+1, board, word, s, visited)) return true;
            if(!s.empty()) s.pop_back();
            visited[i+1][j] = false;
        }
        //Left
        if(j-1 >= 0 && board[i][j-1] == word[idx] && visited[i][j-1] == false){
            s += board[i][j-1];
            visited[i][j-1] = true;
            if(solve(i, j-1, idx+1, board, word, s, visited)) return true;
            if(!s.empty()) s.pop_back();
            visited[i][j-1] = false;
        }
        //Right
        if(j+1 < board[0].size() && board[i][j+1] == word[idx] && visited[i][j+1] == false){
            s += board[i][j+1];
            visited[i][j+1] = true;
            if(solve(i, j+1, idx+1, board, word, s, visited)) return true;
            if(!s.empty()) s.pop_back();
            visited[i][j+1] = false;
        }
        //Up
        if(i-1 >= 0 && board[i-1][j] == word[idx] && visited[i-1][j] == false){
            s += board[i-1][j];
            visited[i-1][j] = true;
            if(solve(i-1, j, idx+1, board, word, s, visited)) return true;
            if(!s.empty()) s.pop_back();
            visited[i-1][j] = false;
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        string s;
        int i = 0, j = 0, idx = 0;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        for(i = 0; i < board.size(); i++){
            for(j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[0]){
                    string s = "";
                    s += board[i][j];
                    visited[i][j] = true;
                    if(solve(i,j,1,board,word,s,visited)) return true;
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }
};