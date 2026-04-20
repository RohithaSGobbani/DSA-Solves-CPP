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

Node* removeNthFromEnd(Node* head, int n) {
    if(head == NULL || head->next == NULL) return NULL;
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        temp = temp->next;
    }
    int pos = cnt - n;
    cnt = 0;
    temp = head;
    if(pos == 0){
        head = head->next;
    }
    while(temp != NULL){
        cnt++;
        if(pos == cnt){
            Node* deleteNode = temp->next;
            temp->next = temp->next->next;
            delete deleteNode;
        }
        temp = temp->next;
    }
    return head;
}

Node* removeNthFromEndOptimal(Node* head, int n) {
    if(head == NULL || head->next == NULL) return NULL;
    Node* fast = head;
    while(n > 0){
        fast = fast->next;
        n--;
    }
    if(fast == NULL) return head->next;
    Node* slow = head;
    while(fast->next != NULL){
        fast = fast->next;
        slow = slow->next;
    }
    Node* deleteNode = slow->next;
    slow->next = slow->next->next;
    delete deleteNode;
    return head;
}

/*
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
*/

int main(){
    vector<int> arr = {1,2,3,4,5};
    int n;
    cin >> n;
    Node* head = convertArray2LL(arr);
    print(head);
    head = removeNthFromEndOptimal(head, n);
    print(head);
    return 0;
}