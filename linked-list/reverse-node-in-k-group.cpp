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

Node* findkthNode(Node* node, int k){
    k -= 1;
    while(node != NULL && k > 0){
        node = node->next;
        k--;
    }
    return node;
}
Node* reverse(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* newHead = reverse(head->next);
    Node* front = head->next; 
    front->next = head;
    head->next = NULL;
    return newHead;
}
Node* reverseKGroup(Node* head, int k) {
    if(head == NULL || head->next == NULL) return head;
    Node* temp = head, *nextNode = NULL, *prevNode = NULL;
    while(temp != NULL){
        Node* kthNode = findkthNode(temp, k);
        if(kthNode == NULL){
            if(prevNode) prevNode->next = temp;
            break;
        }
        nextNode = kthNode->next;
        kthNode->next = NULL;
        reverse(temp);
        if(temp == head){
            head = kthNode;
        }else{
            prevNode->next = kthNode;
        }
        prevNode = temp;
        temp = nextNode;
    }
    return head;
}

/*
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
*/

int main(){
    vector<int> arr = {1,2,3,4,5};
    Node* head = convertArray2LL(arr);
    print(head);
    int k = 2;
    head = reverseKGroup(head, k);
    print(head);
    return 0;
}