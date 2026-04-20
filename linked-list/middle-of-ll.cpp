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

Node* middleNode(Node* head) {
    if(head == NULL || head->next == NULL) return head;
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        temp = temp->next;
    }
    Node* temp1 = head;
    int n = 0;
    while(temp1 != NULL){
        n++;
        if(n == ((cnt/2) + 1)) return temp1;
        temp1 = temp1->next;
    }      
    return NULL;
}

/*
Input: head = [1,2,3,4,5]
Output: [3,4,5]
*/

int main(){
    vector<int> arr = {1,2,3,4,5};
    Node* head = convertArray2LL(arr);
    print(head);
    head = middleNode(head);
    print(head);
    return 0;
}