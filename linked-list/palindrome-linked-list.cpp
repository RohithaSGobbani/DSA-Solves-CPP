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

bool isPalindrome(Node* head) {
    stack<int> st;
    Node* temp = head;
    while(temp != NULL){
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp != NULL){
        if(temp->data != st.top()) return false;
        st.pop();
        temp = temp->next;
    }
    return true;
}

Node* rev(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* newHead = rev(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}
bool isPalindromeOptimal(Node* head) {
    if(head == NULL || head->next == NULL) return true;
    Node* slow = head;
    Node* fast = head;
    while(fast->next != NULL && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* newHead = rev(slow->next);
    Node* first = head;
    Node* second = newHead;
    while(second != NULL){
        if(first->data != second->data){
            rev(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    rev(newHead);
    return true;
}

/*
Input: head = [1,2,2,1]
Output: true
*/

int main(){
    vector<int> arr = {1,2,2,1};
    Node* head = convertArray2LL(arr);
    print(head);
    cout << isPalindromeOptimal(head);
    return 0;
}