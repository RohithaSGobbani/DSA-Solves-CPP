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

Node* reverseLL(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* newHead = reverseLL(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

Node *addOne(Node *head)
{
    if(head == NULL) return head;
    // Write Your Code Here.
    head = reverseLL(head);
    Node* temp = head;
    int carry = 1;
    while(temp != NULL){
        int num = temp->data + carry;
        temp->data = num;
        if(num > 9) {
            carry = 1;
            temp->data = num % 10;
        }
        else{
            carry = 0;    
            break;
        }
        temp = temp->next;
    }
    head = reverseLL(head);
    if(carry){
        Node* newNode = new Node(1, head);
        return newNode;
    }
    return head;
}

int main(){
    vector<int> arr = {1,5,2};
    Node* head = convertArray2LL(arr);
    print(head);
    head = addOne(head);
    print(head);
    return 0;
}