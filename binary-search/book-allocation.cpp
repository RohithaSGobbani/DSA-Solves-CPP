#include<bits/stdc++.h>
using namespace std;

//Brute
int canallocate(vector<int> &arr, int pages){
    int stu = 1, pagesstudents = 0;
    int n = arr.size();
    for(int i = 0; i < n; i++){
        if(pagesstudents + arr[i] <= pages){
            pagesstudents += arr[i];
        }else{
            stu++;
            pagesstudents = arr[i];
        }
    }
    return stu;
}
int book_min(vector<int> &arr, int students){
    if(arr.size() < students) return -1;
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);
    for(int pages = low; pages <= high; pages++){
        if(canallocate(arr,pages) == students){
            return pages;
        }
    }
    return -1;
}

//BS
int book_minBS(vector<int> &arr, int students){
    if(arr.size() < students) return -1;
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);
    while(low <= high){
        int mid = low + (high - low)/2;
        if(canallocate(arr,mid) <= students){
            high = mid - 1;
        }else{
            low = mid+1;
        }
    }
    return low;
}

int main(){
    int n;
    cin >> n; 
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int students;
    cin >> students;
    cout << book_minBS(arr,students);
}