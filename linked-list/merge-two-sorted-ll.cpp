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

Node* sort(Node* first, Node* second){
    Node* t1 = first;
    Node* t2 = second;
    Node* dummy = new Node(-1);
    Node* t = dummy;
    while(t1 && t2){
        if(t1->data >= t2->data){
            t->next = t2;
            t = t->next;
            t2 = t2->next;
        }else{
            t->next = t1;
            t = t->next;
            t1 = t1->next;
        }
    }
    while(t1){
        t->next = t1;
        t = t->next;
        t1 = t1->next;
    }
    
    while(t2){
        t->next = t2;
        t = t->next;
        t2 = t2->next;
    }
    return dummy->next;
}

int main(){
    vector<int> arr1 = {7,8};
    vector<int> arr2 = {1,3,4,6};
    Node* first = convertArray2LL(arr1);
    Node* second = convertArray2LL(arr2);
    Node* head = sort(first, second);
    print(head);
    return 0;
}