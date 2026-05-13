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
    Node* back = head;
    int n = arr.size();
    for(int i = 1; i < n; i++){
        Node* temp = new Node(arr[i], nullptr, back);
        back->next = temp;
        back = temp;
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


Node * removeDuplicates(Node *head)
{
    // Write your code here
    if(head == NULL || head->next == NULL) return head;
    Node* t = head;
    while(t != NULL && t->next != NULL){
        Node* n = t->next;
        if(!n) return head;
        while(n && t->data == n->data){
            Node* d = n;
            n = n->next;
            free(d);
        }
        t->next = n;
        if(n)
            n->back = t;
        t = t->next;
    }
    return head;
}

int main(){
    vector<int> arr = {1,2,2,2,3};
    Node* head = convertArray2DLL(arr);
    print(head);
    head = removeDuplicates(head);
    print(head);
    return 0;
}