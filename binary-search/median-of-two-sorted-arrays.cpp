#include<bits/stdc++.h>
using namespace std;

//Brute
int medianBrute(vector<int> &arr1, vector<int> &arr2){
    int n1 = arr1.size();
    int n2 = arr2.size();
    vector<int> arr3;
    int i = 0, j = 0;
    while(i < n1 && j < n2){
        if(arr1[i] < arr2[j]) arr3.push_back(arr1[i++]);
        else arr3.push_back(arr2[j++]);
    }
    while(i < n1) arr3.push_back(arr1[i++]);
    while(j < n2) arr3.push_back(arr2[j++]);
    int n = arr3.size();
    if(n % 2 == 1) return arr3[n/2];
    else return (arr3[n/2] + arr3[(n/2)-1])/2;
}

//Better
int medianBetter(vector<int> &arr1, vector<int> &arr2){
    int n1 = arr1.size();
    int n2 = arr2.size();
    int n = n1 + n2;
    int ind1 = n/2, ind2 = (n/2)-1;
    int ind1ele = -1 , ind2ele = -1;
    int i = 0, j = 0;
    int cnt = 0;
    while(i < n1 && j < n2){
        if(arr1[i] < arr2[j]){
            if(cnt == ind1) ind1ele = arr1[i];
            if(cnt == ind2) ind2ele = arr1[i];
            cnt++;
            i++;
        }else{
            if(cnt == ind1) ind1ele = arr2[j];
            if(cnt == ind2) ind2ele = arr2[j];
            cnt++;
            j++;            
        }
    }
    while(i < n1){
        if(cnt == ind1) ind1ele = arr1[i];
        if(cnt == ind2) ind2ele = arr1[i];
        cnt++;
        i++;        
    }
    while(j < n2){
        if(cnt == ind1) ind1ele = arr2[j];
        if(cnt == ind2) ind2ele = arr2[j];
        cnt++;
        j++;        
    }
    if(n % 2 == 1) return ind2ele;
    else return (ind2ele + ind1ele)/ 2.0;
}

//Optimal
int medianOptimal(vector<int> &arr1, vector<int> &arr2){
    int n1 = arr1.size();
    int n2 = arr2.size();
    if(n1 > n2) return medianOptimal(arr2, arr1);
    int low = 0, high = n1;
    int left = (n1+n2+1)/2;
    int n = n1+n2;
    while(low <= high){
        int mid1 = low + (high - low) >> 1;
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if(mid1 < n1) r1 = arr1[mid1];
        if(mid2 < n2) r2 = arr2[mid2];
        if(mid1 - 1 >= 0) l1 = arr1[mid1-1];
        if(mid2-1 >= 0) l2 = arr2[mid2-1];
        if(l1 <= r2 && l2 <= r1){
            if(n % 2 == 1) return max(l1,l2);
            return (double)(max(l1,l2) + min(r1,r2)) / 2.0;
        }else if(l1 > r2) high = mid1-1;
        else low = mid1+1;
    }
    return 0;
}

/*
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
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
    cout<< medianOptimal(arr1, arr2);
    return 0;
}