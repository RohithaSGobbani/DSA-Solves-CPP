#include<bits/stdc++.h>
using namespace std;

void insert(stack<int> &st, int element){
    if(st.empty() || st.top() <= element){
        st.push(element);
        return;
    }
    int top_element = st.top();
    st.pop();
    insert(st, element);
    st.push(top_element);
}
void sortStack(stack<int> &st) {
    // Your code goes here
    if(st.empty()){
        return;
    }
    int top_element = st.top();
    st.pop();
    sortStack(st);
    insert(st, top_element);
}

int main() {
    stack<int> s;
    s.push(4);
    s.push(1);
    s.push(3);
    s.push(2);

    sortStack(s);

    // Print the sorted stack
    cout << "Sorted stack (descending order): ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}