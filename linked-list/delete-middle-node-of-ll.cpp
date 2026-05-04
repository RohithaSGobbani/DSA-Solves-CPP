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

Node* deleteMiddle(Node* head) {
    if(head == NULL || head->next == NULL) return NULL;
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* temp = head;
    while(temp->next != slow){
        temp = temp->next;
    }
    temp->next = slow->next;
    delete slow;
    return head;
}

/*
Input: head = [1,3,4,7,1,2,6]
Output: [1,3,4,1,2,6]
*/

int main(){
    vector<int> arr = {1,3,4,7,1,2,6};
    Node* head = convertArray2LL(arr);
    print(head);
    head = deleteMiddle(head);
    print(head);
    return 0;
}