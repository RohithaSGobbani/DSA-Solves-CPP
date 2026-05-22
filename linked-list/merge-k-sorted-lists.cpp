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

Node* convert(vector<int> &arr){
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

//Brute
Node* mergeKLists(vector<Node*>& lists) {
    int n = lists.size();
    vector<int> arr;
    for(int i = 0; i < n; i++){
        Node* t = lists[i];
        while(t){
            arr.push_back(t->data);
            t = t->next;
        }
    }
    sort(arr.begin(), arr.end());
    Node* head = convert(arr);
    return head;
}

//Better
Node* merge2list(Node* l1, Node* l2){
    Node* t1 = l1;
    Node* t2 = l2;
    Node* dummy = new Node(-1);
    Node* curr = dummy;
    while(t1 && t2){
        if(t1->data <= t2->data){
            curr->next = t1;
            curr = curr->next;
            t1 = t1->next;
        }else{
            curr->next = t2;
            curr = curr->next;
            t2 = t2->next;
        }
    }
    while(t1){
        curr->next = t1;
        curr = curr->next;
        t1 = t1->next;
    }
    while(t2){
        curr->next = t2;
        curr = curr->next;
        t2 = t2->next;
    }
    return dummy->next;
}

Node* mergeKListsBetter(vector<Node*>& lists) {
    if(lists.size() == 0) return NULL;
    Node* head = lists[0];
    for(int i = 1; i < lists.size(); i++){
        head = merge2list(head, lists[i]);
    }
    return head;
}

Node* mergeKListsOptimal(vector<Node*> lists){
    priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>>> pq;
    for(int i = 0; i < lists.size(); i++){
        if(lists[i])
        pq.push({lists[i]->data, lists[i]});
    }
    Node* dummy = new Node(-1);
    Node* temp = dummy;
    while(!pq.empty()){
        pair<int, Node*> p = pq.top();
        temp->next = p.second;
        pq.pop();
        if(p.second->next)
            pq.push({p.second->next->data, p.second->next});
        temp = temp->next;
    }
    return dummy->next;
}

int main() {
    vector<int> arr1 = {1, 4, 5};
    vector<int> arr2 = {1, 3, 4};
    vector<int> arr3 = {2, 6};

    Node* list1 = convert(arr1);
    Node* list2 = convert(arr2);
    Node* list3 = convert(arr3);

    vector<Node*> lists = {list1, list2, list3};

    Node* mergedListHead = mergeKListsOptimal(lists);


    cout << "Merged List: ";
    print(mergedListHead);

    return 0;
}