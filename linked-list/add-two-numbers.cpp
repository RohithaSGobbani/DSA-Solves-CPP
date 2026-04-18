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

Node* addTwoNumbers1(Node* l1, Node* l2) {
    Node* t1 = l1;
    Node* t2 = l2;
    Node* dummyNode = new Node(-1);
    Node* curr = dummyNode;
    long long carry = 0;
    while(t1 != NULL || t2 != NULL){
        if(t1 == NULL){
            long long data = t2->data + carry;
            if(data >= 10) {
                int c = data % 10;
                Node* newNode = new Node(c);
                curr->next = newNode;
            }else{
                Node* newNode = new Node(data);
                curr->next = newNode;   
            }
            carry = data / 10;
            t2 = t2->next;
        }else if(t2 == NULL){
            long long data = t1->data + carry;
            if(data >= 10) {
                int c = data % 10;
                Node* newNode = new Node(c);
                curr->next = newNode;
            }else{
                Node* newNode = new Node(data);
                curr->next = newNode;   
            }
            carry = data / 10;
            t1 = t1->next;
        }else{
            long long data = t1->data + t2->data + carry;
            if(data >= 10) {
                int c = data % 10;
                Node* newNode = new Node(c);
                curr->next = newNode;
            }else{
                Node* newNode = new Node(data);
                curr->next = newNode;   
            }
            carry = data / 10;
            t1 = t1->next;
            t2 = t2->next;
        }
        curr = curr->next;
    }
    if(carry != 0){
        Node* carryNode = new Node(carry);
        curr->next = carryNode;
    }
    
    return dummyNode->next;
}



/*
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
*/

int main(){
    vector<int> l1 = {2,4,3};
    vector<int> l2 = {5,6,4};
    Node* head1 = convertArray2LL(l1);
    Node* head2 = convertArray2LL(l2);
    Node* sum = addTwoNumbers(head1, head2);
    print(sum);
}