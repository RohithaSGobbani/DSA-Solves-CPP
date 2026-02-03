
"""
Input: nums = [1,2,2,4]
Output: [2,3]
"""

vector<int> findErrorNums(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans;
    unordered_set<int> st;
    int repeated, missing;
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n; i++){
        if(st.find(arr[i]) != st.end()){
            repeated = arr[i];
        }else{
            st.insert(arr[i]);
        }
        if(st.find(i+1) == st.end()){
            missing = i+1;
        }
    }
    ans.push_back(repeated);
    ans.push_back(missing);
    return ans;
}