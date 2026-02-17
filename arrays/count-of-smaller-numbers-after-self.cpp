class Solution {
public:
    void merge(vector<int> &arr, vector<int> &idx, vector<int> &counts, int low, int mid, int high){
        int left = low;
        int right = mid+1;
        int cnt = 0;
        vector<int> temp;
        while(left <= mid && right <= high){
            if(arr[idx[left]] <= arr[idx[right]]){
                counts[idx[left]] += cnt;                
                temp.push_back(idx[left]);
                left++;
            }else{
                cnt++;
                temp.push_back(idx[right]);
                right++;
            }
        }
        while(left <= mid){
            counts[idx[left]] += cnt;                
            temp.push_back(idx[left]);
            left++;
        }
        while(right <= high){
            temp.push_back(idx[right]);
            right++;
        }
        for(int i = low; i <= high; i++){
            idx[i] = temp[i - low];
        }
    }
    void mergeSort(vector<int> &arr, vector<int> &idx, vector<int> &counts, int low, int high){
        if(low >= high) return;
        int mid = (low + high) / 2;
        mergeSort(arr, idx, counts, low, mid);
        mergeSort(arr, idx, counts, mid+1, high);
        merge(arr, idx, counts, low, mid, high);
    }
    vector<int> countSmaller(vector<int>& arr) {
        int n = arr.size();
        if(n==0) return {};

        vector<int> counts(n,0);
        vector<int> idx(n);

        for(int i = 0; i < n; i++){
            idx[i] = i;
        }
        mergeSort(arr, idx, counts, 0, n-1);
        return counts;
    }
};