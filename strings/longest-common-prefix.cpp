#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return ""; 

    sort(strs.begin(), strs.end());
    
    string first = strs[0];
    string last = strs.back(); // Same as strs[strs.size()-1]
    
    size_t i = 0; // Fixed signedness warning
    while (i < first.size() && i < last.size() && first[i] == last[i]) {
        i++;
    }
    
    return first.substr(0, i);
}

/*
Input: strs = ["flower","flow","flight"]
Output: "fl"
*/

int main() {
    int n;
    if (!(cin >> n)) return 0; // Ensure n is actually read
    
    vector<string> strs(n);
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }
    
    cout << longestCommonPrefix(strs) << endl;
    return 0;
}