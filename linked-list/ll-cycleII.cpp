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

/*
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
*/

Node *detectCycle(Node *head) {
    if(head == NULL || head->next == NULL) return NULL;
    unordered_map<Node*, int> mp;
    Node* temp = head;
    while(temp != NULL){
        if(mp.find(temp) != mp.end()) return temp;
        mp[temp] = 1;
        temp = temp->next;
    }
    return NULL;
}

//Optimal
NOde *detectCycleOptimal(NOde *head) {
    if(head == NULL || head->next == NULL) return NULL;
    NOde* fast = head;
    NOde* slow = head;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(slow == fast) break;
    }
    if(!(fast && fast->next)) return NULL;
    NOde* temp = head;
    while(temp != slow){
        temp = temp->next;
        slow = slow->next;
    }
    return temp;
}