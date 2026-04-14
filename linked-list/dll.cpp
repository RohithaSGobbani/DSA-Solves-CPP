#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* convertArray2DLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    int n = arr.size();
    for(int i = 1; i < n; i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
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

Node* deleteHead(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    
    Node* prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;

    delete prev;
    return head;
}

Node* deleteTail(Node* head){
    if(head == NULL || head->next == NULL) return NULL;

    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    temp->next->back = nullptr;
    temp->next = nullptr;
    
    free(temp->next);
    return head;
}

int main(){
    vector<int> arr = {10,5, 8, 9};
    Node* head = convertArray2DLL(arr);
    head = deleteTail(head);
    print(head);
}