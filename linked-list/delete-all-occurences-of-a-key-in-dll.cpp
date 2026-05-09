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

Node* deleteOccurences(Node* head, int key){
    if(head == NULL) return head;
    // while(head->data == key){
    //     Node* temp = head;
    //     head = head->next;
    //     delete temp;
    // }
    Node* temp = head;

    while(temp != NULL){
        if(temp->data == key){
            if(temp == head){
                head = head->next;
            }
            Node* nextNode = temp->next;
            Node* prevNode = temp->back;   
            if(nextNode) nextNode->back = prevNode;
            if(prevNode) prevNode->next = nextNode;        
            free(temp);
            temp = nextNode;
        }else{
            temp = temp->next;
        }
    }
    return head;
}

int main(){
    vector<int> arr = {10,4, 10, 10, 6, 10};
    Node* head = convertArray2DLL(arr);
    print(head);
    head = deleteOccurences(head, 10);
    print(head);
    return 0;
}