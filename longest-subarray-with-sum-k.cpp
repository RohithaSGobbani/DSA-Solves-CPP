#include<bits/stdc++.h>
using namespace std;

//Brute
int longestSubarraywithsumkBrute(vector<int> &arr, int k){
    int len = 0, n = arr.size();
    for(int i = 0; i < n; i++){
        int currentSum = 0;
        for(int j = i; j < n; j++){    
            currentSum += arr[j];
            if(currentSum == k){
                len = max(len, j - i + 1);
            }       
        }
 
    }
    return len;
}

//Better
int longestSubarrayBetter(vector<int>& a, long long k) {
    int n = a.size();
    
    // 2. The Storage: Key = Prefix Sum, Value = Index
    unordered_map<long long, int> preSumMap; 
    
    long long sum = 0;   // Keeps track of the total sum from index 0 to i
    int maxLen = 0;      // Stores the final answer

    for (int i = 0; i < n; i++) {
        // A. Add current element to the running total
        sum += a[i];

        // B. Check if the sum from the very beginning is already K
        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }

        // C. The Search Logic: sum - K
        long long rem = sum - k; 

        // If 'rem' exists in our map, it means the subarray between 
        // the stored index and 'i' sums up to K.
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        // D. The Record Logic:
        // We only add 'sum' to the map if it's NOT already there.
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }
    return maxLen;
}

//Optimal
int longestSubarrayOptimal(vector<int> &arr, int k){
    int j = 0, n = arr.size();
    int sum = 0, maxLen = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
// 2. If sum exceeds k, shrink the window from the j
        // We use 'while' because we might need to remove multiple elements
        while (j <= i && sum > k) {
            sum -= arr[j];
            j++;
        }

        // 3. If we found a sum equal to k, calculate the length
        if (sum == k) {
            maxLen = max(maxLen, i - j + 1);
        }
    }
    return maxLen;
}

/*
Input: arr = [1,2,3,1,1,1,1,4,2,3], k = 3
Output: 3
*/

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << longestSubarrayOptimal(arr, 3);
    return 0;
}
