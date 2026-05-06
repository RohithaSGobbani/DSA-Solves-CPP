#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convertArray2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = mover->next;
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

Node* sortList(Node* head) {
    if(head == NULL || head->next == NULL) return head;
    vector<int> arr;
    Node* temp = head;
    while(temp != NULL){
        arr.push_back(temp->data);
        temp = temp->next;
    }
    sort(arr.begin(), arr.end());
    temp = head;
    int i = 0;
    while(temp != NULL){
        temp->data = arr[i++];
        temp = temp->next;
    }
    return head;
}

/*
Input: head = [4,2,1,3]
Output: [1,2,3,4]
*/

int main(){
    vector<int> arr = {4,2,1,3};
    Node* head = convertArray2LL(arr);
    print(head);
    head = sortList(head);
    print(head);
    return 0;
}