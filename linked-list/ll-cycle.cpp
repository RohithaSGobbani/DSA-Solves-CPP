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

//Brute
bool hasCycle(Node *head) {
    unordered_map<Node*, int> mp;
    Node* temp = head;
    while(temp  != NULL){
        if(mp.find(temp) != mp.end()) return true;
        mp[temp] = 1;
        temp = temp->next;
    }
    return false;
}

//Better: TortoiseHare
bool hasCycleBetter(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}