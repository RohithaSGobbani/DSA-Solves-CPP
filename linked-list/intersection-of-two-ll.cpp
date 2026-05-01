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

Node *getIntersectionNode(Node *headA, Node *headB) {
    unordered_map<Node*, int> mp;
    Node* temp1 = headA;
    Node* temp2 = headB;
    while(temp1 != NULL){
        mp[temp1] = 1;
        temp1 = temp1->next;
    }
    while(temp2 != NULL){
        if(mp.find(temp2) != mp.end()){
            return temp2;
        }
        temp2 = temp2->next;
    }
    return NULL;
}


/*
Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Intersected at '8'
*/

