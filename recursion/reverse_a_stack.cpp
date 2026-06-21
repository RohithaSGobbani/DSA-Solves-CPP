#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &st, int element){
    if(st.empty()){
        st.push(element);
        return;
    }
    int top_element = st.top();
    st.pop();
    insertAtBottom(st, element);
    st.push(top_element);

}

void reverseStack(stack<int> &st) {
    // Write your code here
    if(st.empty()) return;

    int top_element = st.top();
    st.pop();

    reverseStack(st);
    insertAtBottom(st, top_element);
}

int main() {
    stack<int> s;
    s.push(4);
    s.push(1);
    s.push(3);
    s.push(2);

    reverseStack(s);

    // Print the sorted stack
    cout << "Reversed: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}