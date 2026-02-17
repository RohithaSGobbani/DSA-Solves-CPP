#include<bits/stdc++.h>
using namespace std;

//Brute
void mergeBrute(vector<vector<int>> &arr){
    int n = arr.size();
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;

    for(int i = 0; i < n; i++){
        int start = arr[i][0];
        int end = arr[i][1];
        if(!ans.empty() && end <= ans.back()[1]){
            continue;
        }
        for(int j = i+1; j < n; j++){
            if(arr[j][0] <= end){
                end = max(end, arr[j][1]);
            }else{
                break;
            }
        }
        ans.push_back({start, end});
    }
    for(auto &row : ans){
        for(auto a:row){
            cout << a << " ";
        }
        cout << endl;
    }
}

//Optimal
void mergeOptimal(vector<vector<int>> &arr){
    int n = arr.size();
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    for(int i = 0; i < n; i++){
        if(ans.empty() || arr[i][0] > ans.back()[1]){
            ans.push_back(arr[i]);
        }
        else{
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    for(auto &row : ans){
        for(auto a:row){
            cout << a << " ";
        }
        cout << endl;
    }    
}

/*
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
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
    mergeOptimal(arr);
    return 0;
}