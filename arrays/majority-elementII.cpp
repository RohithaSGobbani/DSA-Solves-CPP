#include<bits/stdc++.h>
using namespace std;

//Brute
void majorityeleBrute(vector<int> &arr){
    int n = arr.size();
    int cnt = 0;
    vector<int> ans;
    for(int i = 0; i < n; i++){
        cnt = 1;
        if(ans.size() == 0 || ans[0] != arr[i]){
            for(int j = i+1; j < n; j++){
                if(arr[i] == arr[j]){
                    cnt++;
                }
            }
            if(cnt > n/3){
                ans.push_back(arr[i]);
            }
        }        
    }
    for(auto a:ans){
        cout << a << " ";
    }
}

//Better
void majorityeleBetter(vector<int> &arr){
    int n =arr.size();
    unordered_map<int,int> mp;
    vector<int> ans;
    int mini = (n/3) + 1;
    for(int i = 0; i < n; i++){
        mp[arr[i]]++;
        if(mp[arr[i]] == mini){
            ans.push_back(arr[i]);
        }
    }

    for(auto a:ans){
        cout << a << " ";
    }
}

//Optimal
void majorityeleOptimal(vector<int> &arr){
    int n = arr.size();
    int cnt1 = 0, cnt2 = 0;
    int ele1, ele2;
    for(int i = 0; i < n; i++){
        if(cnt1 == 0 && arr[i] != ele2){
            cnt1 = 1;
            ele1 = arr[i];
        }else if(cnt2 == 0 && arr[i] != ele1){
            cnt2 = 1;
            ele2 = arr[i];
        }else if(ele1 == arr[i]) cnt1++;
        else if(ele2 == arr[i]) cnt2++;
        else{
            cnt1--;
            cnt2--;
        }
    }
    vector<int> ans;
    cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n; i++){
        if(ele1 == nums[i]) cnt1++;
        if(ele2 == nums[i]) cnt2++;
    }
    int mini = (n/3) + 1;
    if(cnt1 >= mini) ans.push_back(ele1);
    if(cnt2 >= mini) ans.push_back(ele2);
    cout << ans[0] << " " << ans[1];
}

/*
Input: 1 1 1 3 3 2 2 2
Output: 1 2
*/

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    majorityeleOptimal(arr);
    return 0;
}