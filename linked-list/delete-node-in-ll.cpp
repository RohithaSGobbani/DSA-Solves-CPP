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

void deleteNode(Node* node) {
    node->data = node->next->data;
    node->next = node->next->next;
}

void print(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;    
}

/*
Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
*/

int main(){
    vector<int> arr = {12,5,8,7};
    Node* head = convertArray2LL(arr);
    deleteNode(head->next);
    print(head);
}