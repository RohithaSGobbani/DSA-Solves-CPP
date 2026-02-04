#include<bits/stdc++.h>
using namespace std;

void buynsell(vector<int> &arr){
    int mini = arr[0], profit = 0;
    int n = arr.size();
    for(int i = 0; i < n; i++){
        int cost = arr[i] - mini;
        profit = max(profit, cost);
        mini = min(mini, arr[i]);
    }
    cout << profit;
}

/*
Input: arr = [7,1,5,3,6,4]
Output: 5
*/

int main(){
    int n; 
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    buynsell(arr);
    return 0;
}
