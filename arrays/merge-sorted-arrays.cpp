#include<bits/stdc++.h>
using namespace std;

//Brute
void mergeBrute(vector<int> &arr1, vector<int> &arr2){
    int n = arr1.size();
    int m = arr2.size();
    vector<int> ans(n+m);
    int left = 0;
    int right = 0;
    int index = 0;
    while(left < n && right < m){
        if(arr1[left] <= arr2[right]){
            ans[index] = arr1[left];
            left++; index++;
        }
        else{
            ans[index] = arr2[right];
            right++; index++;
        }
    }
    while(left < n){
        ans[index++] = arr1[left++];
    }

    while(right < m){
        ans[index++] = arr2[right++];
    }

    for(int i = 0; i < n; i++){
        if(i < n) arr1[i] = ans[i];
        else arr2[i-n] = ans[i];
    }

    for(auto a : arr1){
        cout << a << " ";
    }
    cout << endl;
    for(auto a : arr2){
        cout << a << " ";
    }     
}

//Optimal1 : two pointer
void mergeOptimal1(vector<int> &arr1, vector<int> &arr2){
    int n = arr1.size();
    int m = arr2.size();
    int left = n-1;
    int right = 0;
    while(left >= 0 && right < m){
        if(arr1[left] > arr2[right]){
            int temp = arr1[left];
            arr1[left] = arr2[right];
            arr2[right] = temp;
            left--; right++;
        }else{
            break;
        }
    }
    sort(arr1.begin(), arr1.end());
    sort(arr1.begin(), arr1.end());

    for(auto a : arr1){
        cout << a << " ";
    }
    cout << endl;
    for(auto a : arr2){
        cout << a << " ";
    }    
}    

//Optimal2 : Gap method(
void swapIfGreater(vector<int> &arr1, vector<int> &arr2, int ind1, int ind2){
    if(arr1[ind1] > arr1[ind2]){
        swap(arr1[ind1] , arr2[ind2]);
    }
}
void mergeOptimal2(vector<int> &arr1, vector<int> &arr2){
    int n = arr1.size();
    int m = arr2.size();
    int len = n + m;
    int gap  = (len / 2) + (len % 2);
    while(gap > 0){
        int left = 0;
        int right = left + gap;
        while(right < len){
            //In arr1 & arr2
            if(left < n && right >= n){
                swapIfGreater(arr1, arr2, left, right - n);
            }
            //arr2 & arr2
            else if(left >= n){
                swapIfGreater(arr2, arr2, left - n, right - n);
            }
            //arr1 & arr1
            else{
                swapIfGreater(arr1, arr1, left, right);
            }
            left++; right++;
        }
        if(gap == 1) break;
        gap = (gap / 2) + (gap % 2);
    }
    for(auto a : arr1){
        cout << a << " ";
    }
    cout << endl;
    for(auto a : arr2){
        cout << a << " ";
    }  
}    

/*
Input : nums1 = [-5, -2, 4, 5, 0, 0, 0], nums2 = [-3, 1, 8]
Output : [-5, -3, -2, 1, 4, 5, 8]
*/

int main(){
    int n1, n2;
    cin >> n1;
    cin >> n2;
    vector<int> arr1(n1);
    for(int i = 0; i < n1; i++){
        cin >> arr1[i];
    }   
    vector<int> arr2(n2);
    for(int i = 0; i < n2; i++){
        cin >> arr2[i];
    }
    mergeOptimal1(arr1,arr2);
    return 0;
}