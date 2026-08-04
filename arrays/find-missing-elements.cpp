#include<bits/stdc++.h>
using namespace std;

    int maxi(vector<int> &arr){
        int m = INT_MIN;
        for(int i =0; i < arr.size();i++){
            m = max(m,arr[i]);
        }
        return m;
    }
    int mini(vector<int> &arr){
        int m = INT_MAX;
        for(int i =0; i < arr.size();i++){
            m = min(m,arr[i]);
        }
        return m;
    }
    bool found(vector<int> &arr, int m){
        int low=0, high = arr.size()-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(arr[mid] == m) return true;
            if(m < arr[mid]) high = mid-1;
            else low = mid+1;
        }
        return false;
    }
    vector<int> findMissingElements(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int a = mini(arr);
        int b = maxi(arr);
        vector<int> ans;
        for(int i = a; i <= b; i++){
            if(!found(arr, i)){
                ans.push_back(i);
            }
        }
        return ans;
    }

int main(){

	vector<int> arr = {1,4,2,5};
	vector<int> ans = findMissingElements(arr);
	for(auto a: ans){
		cout << a << " ";
	}
	return 0;
}
