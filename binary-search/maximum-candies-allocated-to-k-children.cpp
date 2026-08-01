include<bits/stdc++.h>
using namespace std;

int mini(vector<int> &arr){
        int m = INT_MAX;
        for(int i = 0; i < arr.size(); i++){
            m = min(m,arr[i]);
        }
        return m;
    }
    int maxi(vector<int> &arr){
        int m = INT_MIN;
        for(int i = 0; i < arr.size(); i++){
            m = max(m,arr[i]);
        }
        return m;
    }
    int sum(vector<int> &arr){
        long long sum = 0;
        for(int i = 0; i < arr.size(); i++){
            sum += (long long)arr[i];
        }
        return sum;
    }
    bool distribute(vector<int> &arr, int mid, long long k){

        long long kid = 0;
        for(int i =0 ; i < arr.size(); i++){
            kid += (arr[i]/mid);
        }
        return kid>=k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int low = 1;
        int high = maxi(candies);

        int ans = 0;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(distribute(candies,mid,k)){
                cout << mid << " ";
                ans = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return ans;
}

