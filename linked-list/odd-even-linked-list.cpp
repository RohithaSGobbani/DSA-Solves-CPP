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


Node* oddEvenList(Node* head) {
    if(head == NULL) return head;
    Node* temp = head;
    vector<int> arr;
    while(temp != NULL && temp->next != NULL){
        arr.push_back(temp->data);
        temp = temp->next->next;
    }
    if(temp) arr.push_back(temp->data);
    temp = head->next;
    while(temp != NULL && temp->next != NULL){
        arr.push_back(temp->data);
        temp = temp->next->next;
    }
    if(temp) arr.push_back(temp->data);
    temp = head;
    int i = 0;
    while(temp != NULL){
        temp->data = arr[i++];
        temp = temp->next;
    }
    return head;
}

Node* oddEvenListOptimal(Node* head) {
    if(head == NULL || head->next == NULL) return head;
    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = even;
    while(even != NULL && even->next != NULL){
        odd->next = odd->next->next;
        odd = odd->next;
        even->next = even->next->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}

/*
Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]
*/

int main(){
    vector<int> arr = {1,2,3,4,5};
    Node* head = convertArray2LL(arr);
    print(head);
    head = oddEvenListOptimal(head);
    print(head);
}