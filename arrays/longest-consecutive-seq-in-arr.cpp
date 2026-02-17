#include<bits/stdc++.h>
using namespace std;

bool ls(vector<int> &arr, int num){
    int n = arr.size();
    for(int i = 0; i < n; i++){
        if(arr[i] == num){
            return true;
        }
    }
    return false;
}

void longestconsecutiveBrute(vector<int> &arr){
    int n = arr.size();
    int cnt,longest = 1;
    for(int i = 0; i < n; i++){
        int x = arr[i];
        cnt = 1;
        while(ls(arr, x+1) == true){
            x = x+1;
            cnt++;
        }
    }
    cout << cnt << endl;
}

void longestconsecutiveBetter(vector<int> &arr){
    int n = arr.size();
    int longest = 1;
    int lastSmall = INT_MIN;
    int cntcur = 0;
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n; i++){
        if(arr[i] - 1 == lastSmall){
            cntcur++;
            lastSmall = arr[i];
        }else if(arr[i] != lastSmall){
            cntcur = 1;
            lastSmall = arr[i];
        }
        longest = max(longest, cntcur);
    }
    cout << longest << endl;
}

int longestconsecutiveOptimal(vector<int> &arr){
    int n = arr.size();
    unordered_set<int> st;
    if(n == 0) return 0;
    int longest = 1;
    for(int i = 0; i < n; i++){
        st.insert(arr[i]);
    }
    for(auto it: st){
        if(st.find(it - 1) == st.end()){
            int cnt = 1;
            int x = it;
            while(st.find(x+1) != st.end()){
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest,cnt);
        }
    }
    return longest;
}

/*
Input: [102,4,100,1,101,3,2,1,1]
Output: 4
*/

int main(){
    int n; 
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    } 
    cout << longestconsecutiveOptimal(arr);
    return 0;    
}