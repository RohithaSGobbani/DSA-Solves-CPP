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

Node* rev(Node* head){
    Node* temp = head;
    Node* prev = nullptr;
    while(temp){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

Node* addTwoNumbers(Node* l1, Node* l2) {
    Node* t1 = rev(l1);
    Node* t2 = rev(l2);
    Node* dummyNode = new Node(-1);
    Node* curr = dummyNode;
    long long carry = 0;
    while(t1 || t2){
        long long sum = carry;
        if(t1) sum = sum + t1->data;
        if(t2) sum = sum + t2->data;
        Node* newNode = new Node(sum % 10);
        carry = sum / 10;
        curr->next = newNode;
        curr = curr->next;
        if(t1) t1 = t1->next;
        if(t2) t2 = t2->next;
    }
    if(carry){
        Node* newNode = new Node(carry);
        curr->next = newNode;
    }
    return rev(dummyNode->next);
    
}

int main(){
    vector<int> arr1 = {7,2,4,3};
    vector<int> arr2 = {5,6,4};
    Node* l1 = convertArray2LL(arr1);
    Node* l2 = convertArray2LL(arr2);
    print(l1);
    print(l2);
    Node* sum = addTwoNumbers(l1, l2);
    print(sum);
    return 0;
}