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

Node* rotateRight(Node* head, int k) {
    if(head == NULL || head->next == NULL || k == 0) return head;
    Node* temp;
    // Node* dummy = new Node(-1);
    while(k > 0){
        temp = NULL;
        Node* curr = head;
        while(curr->next){
            temp = curr;
            curr = curr->next;
        }
        temp->next = NULL;
        curr->next = head;
        head = curr;
        k--;
    }
    return head;
}

/*
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
*/

int main(){
    vector<int> arr = {1,2,3,4,5};
    int k = 2;
    Node* head = convertArray2LL(arr);
    print(head);
    head = rotateRight(head, k);
    print(head);
    return 0;
}