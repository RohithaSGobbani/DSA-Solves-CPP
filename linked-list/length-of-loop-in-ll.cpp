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

int findLengthOfLoop(Node *head) {
    if(head == NULL || head->next == NULL) return 0;
    Node* fast = head;
    Node* slow = head;
    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) break;
    }
    if(!(fast && fast->next)) return 0;
    fast = head;
    while(fast != slow){
        fast = fast->next;
        slow = slow->next;
    }
    unordered_map<Node*, int> mp;
    int n = 0;
    while(slow != NULL){
        if(mp.find(slow) != mp.end()) break;
        n++;
        mp[slow] = 1;
        slow = slow->next;
    }
    return n;
}