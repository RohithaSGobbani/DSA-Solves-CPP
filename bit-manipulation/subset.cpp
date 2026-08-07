#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        int subsets = (1 << n);
        for(int i = 0; i < subsets; i++){
            vector<int> list;
            for(int j = 0; j < n; j++){
                if(i & (1 << j))
                    list.push_back(nums[j]);
            }
            ans.push_back(list);
        }
        return ans;
    }

int main(){
	vector<int> arr = {1 , 2 , 3};
	vector<vector<int>> ans = subsets(arr);
	for(auto a: ans){
		for(auto b: a){
			cout << b << " ";
		}
		cout << endl;
	}
	return 0;

}
