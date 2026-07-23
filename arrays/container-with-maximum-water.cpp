#include<bits/stdc++.h>
using namespace std;

//Brute
int maxAreaBrute(vector<int>& height) {
    int n = height.size();
    int j = 0;
    int mxwater = INT_MIN;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){             
            int width = j - i;
            int h = (height[i] > height[j]) ? height[j] : height[i];
            int water = width * h;
            mxwater = max(mxwater, water);
        }
    }
    return mxwater;
}

int maxAreaOptimal(vector<int>& height) {
    int n = height.size();
    int mxwater = INT_MIN;
    int i = 0;
    int j = n-1;
    while(j > i){
        int width = j - i;
        int h;
        if(height[i] >= height[j]) {
            h = height[j];
            j--;
        }else{
            h = height[i];
            i++;
        } 
        int water = width * h;
        mxwater = max(mxwater, water);
        
    }
    return mxwater;
}

/*
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
*/

int main(){
    vector<int> arr = {1,8,6,2,5,4,8,3,7};
    cout << maxAreaBrute(arr);
    return 0;
}