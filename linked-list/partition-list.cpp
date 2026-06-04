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

Node* partition(Node* head, int x) {
    if(head == NULL || head->next == NULL) return head;
    Node* temp = head;
    Node* dummy = new Node(-1);
    Node* res = dummy;
    Node* dummy2 = new Node(-1);
    Node* greater = dummy2;
    while(temp){
        if(temp->data < x){
            res->next = temp;
            if(res->next) res = res->next;
        }else{
            greater->next = temp;
            if(greater->next)greater = greater->next;
        }
        temp = temp->next;
    }
    res->next = dummy2->next;
    greater->next = nullptr;
    return dummy->next;
}

/*Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]*/

int main(){
    vector<int> arr = {1,4,3,2,5,2};
    Node* head = convertArray2LL(arr);
    print(head);
    head = partition(head, 3);
    print(head);
    return 0;
}