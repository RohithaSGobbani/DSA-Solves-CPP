#include<bits/stdc++.h>
using namespace std;

int secondHighest(string s) {
    set<int> st;
    int n = s.size();
    for(int i = 0; i < n; i++){
        int num = s[i] - '0';
        if(num >= 0 && num <= 9){
            st.insert(num);
        }
    }
    int largest = *st.begin();
    int secondL = -1;
    for(auto a: st){
        if(a > largest){
            secondL = largest;
            largest = a;
        }
    }
    return secondL;
}

