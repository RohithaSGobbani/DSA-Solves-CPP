#include<bits/stdc++.h>
using namespace std;


//BRUTE
void markRow(vector<vector<int>> &arr,int i,int n){
    for(int j = 0; j < n; j++){
        if(arr[i][j] != 0){
            arr[i][j] = -1;
        }
    }
}

void markCol(vector<vector<int>> &arr, int j, int m){
    for(int i = 0; i < m; i++){
        if(arr[i][j] != 0){
            arr[i][j] = -1;
        }
    }
}

void setmatrixz(vector<vector<int>> &arr, int m, int n){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == 0){
                markRow(arr,i,n);
                markCol(arr,j,m);
            }
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == -1){
                arr[i][j] = 0;
            }
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }    
}

//BETTER
void setmatrixzBetter(vector<vector<int>> &arr, int m, int n){
    int row[m] = {0}, col[n] = {0}; 
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == 0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(row[i] || col[j]){
                arr[i][j] = 0;
            }
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }    
}

//OPTIMAL
void setmatrixzOptimal(vector<vector<int>> &arr, int m, int n){
    int col0 = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == 0){
                arr[i][0] = 0;
                if(j != 0){
                    arr[0][j] = 0;
                }else{
                    col0 = 0;
                }
            }
        }
    }
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            if(arr[0][j] == 0 || arr[i][0] == 0){
                arr[i][j] = 0;
            }
        }
    }
    if(arr[0][0] == 0){
        for(int j = 0; j < n; j++){
            arr[0][j] = 0;
        }
    }
    if(col0 == 0){
        for(int i = 0; i < n; i++){
            arr[i][0] = 0;
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }    
}

int main(){
    int m,n;
    cin >> m >> n;
    vector<vector<int>> arr(m, vector<int> (n));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    setmatrixzOptimal(arr, m , n);
    return 0;
}