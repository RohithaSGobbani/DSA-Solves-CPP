#include<bits/stdc++.h>
using namespace std;

//Kadane's Algorithm
int maxSubArray(vector<int>& arr) {
    int n = arr.size();
    int sum = 0;
    int maxi = INT_MIN;
    for(int i = 0; i < n; i++){
        sum += arr[i];
        maxi = max(maxi, sum);
        if(sum < 0){
            sum = 0;
        }
    }
    return maxi;
}

"""
Input: arr = [-2,-3,4,-1,-2,1,5,-3]
Output: 7
"""

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << maxSubArray(arr);
    return 0;
}