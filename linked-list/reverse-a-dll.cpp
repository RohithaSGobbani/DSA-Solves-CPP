#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* convertArray2DLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    int n = arr.size();
    for(int i = 1; i < n; i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void print(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;    
}

//Brute
Node* reverseDLLBrute(Node* head){
    Node* temp = head;
    stack<int> st;
    while(temp != NULL){
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp != NULL){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}

//Optimal
Node* reverseDLLOptimal(Node* head){
    Node* current = head;
    Node* last = NULL;
    while(current != NULL){
        last = current->back;
        current->back = current->next;
        current->next = last;
        current = current->back;
    }
    return last->back;
}

int main(){
    vector<int> arr = {3,9,20,4};
    Node* head = convertArray2DLL(arr);
    print(head);
    head = reverseDLLOptimal(head);
    print(head);
}