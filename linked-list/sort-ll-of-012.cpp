#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};


Node* sortList(Node *head){
    // Write your code here.
    int cnt0 = 0 ,cnt1 = 0, cnt2 = 0;
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == 0) cnt0++;
        else if(temp->data == 1) cnt1++;
        else if(temp->data == 2) cnt2++;
        temp = temp->next;
    }
    temp = head;
    while(temp != NULL){
        if(cnt0){
            temp->data = 0;
            cnt0--;
        }
        else if(cnt0 == 0 && cnt1){
            temp->data = 1;
            cnt1--;
        }
        else if(cnt1 == 0 && cnt2){
            temp->data = 2;
            cnt2--;
        }
        temp = temp->next;
    }
    return head;
}

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


Node* sortListBetter(Node *head){
    // Write your code here.
    Node* temp = head;
    Node* zeroHead = new Node(-1);
    Node* zero = zeroHead;
    Node* oneHead = new Node(-1);
    Node* one = oneHead;
    Node* twoHead = new Node(-1);
    Node* two = twoHead;
    while(temp != NULL){
        if(temp->data == 0){
            zero->next = temp;
            zero = zero->next;
        }else if(temp->data == 1){
            one->next = temp;
            one = one->next;
        }else{
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }
    two->next = nullptr;
    zero->next = oneHead->next;
    one->next = twoHead->next;
    return zeroHead->next;
}

/*
Input: linkedList = [1, 0, 2, 0 , 1]
Output: [0, 0, 1, 1, 2]
*/

int main(){
    vector<int> arr = {1,0,2,0,1};
    Node* head = convertArray2LL(arr);
    print(head);
    head = sortListBetter(head);
    print(head);
    return 0;
}