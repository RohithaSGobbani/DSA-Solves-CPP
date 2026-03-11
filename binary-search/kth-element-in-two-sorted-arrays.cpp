#include<bits/stdc++.h>
using namespace std;

int kthElement(vector<int> &arr1, vector<int> &arr2, int n1, int n2, int k){
    // Write your code here
    if(n1 > n2) kthElement(arr2, arr1, n2,n1,k);
    int low = max(0, k-n2);
    int high = min(k,n1);
    int left = k;
    int n = n1+n2;
    while(low <= high){
        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if(mid1 < n1) r1 = arr1[mid1];
        if(mid2 < n2) r2 = arr2[mid2];
        if(mid1-1 < n1) l1 = arr1[mid1-1];
        if(mid2-1 < n2) l2 = arr2[mid2-1];
        if(l1 <= r2 && l2 <= r1){
            return max(l1,l2);
        }else if(l1 > r2) high = mid1-1;
        else low = mid1+1;
    }
    return 0;
}

/*
Input: a = [2, 3, 6, 7, 9], b = [1, 4, 8, 10], k = 5
Output: 6
*/

int main(){
    int n1, n2;
    cin >> n1 >> n2;
    vector<int> arr1(n1);
    for(int i = 0; i < n1; i++){
        cin >> arr1[i];
    }
    vector<int> arr2(n2);
    for(int i = 0; i < n2; i++){
        cin >> arr2[i];
    }
    int k;
    cin >> k;
    cout<< kthElement(arr1, arr2, n1,n2,k);
    return 0;
}