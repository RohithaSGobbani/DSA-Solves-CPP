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