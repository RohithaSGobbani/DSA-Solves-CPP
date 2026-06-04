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

void reorderList(Node* head) {
    stack<Node*> st;
    Node* temp = head;
    int n = 0;
    while(temp){
        st.push(temp);
        n++;
        temp = temp->next;
    }
    temp = head;
    int i = 0;
    Node* nextNode = temp->next;
    while(temp && n > 0){
        if(i % 2 == 0){
            temp->next = st.top();
            st.pop();
            temp = temp->next;
            i++;
        }else{
            temp->next = nextNode;
            temp = temp->next;
            nextNode = temp->next;
            i++;
        }
        n--;
    }
    temp->next = nullptr;
}

/*
Input: head = [1,2,3,4]
Output: [1,4,2,3]
*/

int main(){
    vector<int> arr = {1,2,3,4};
    Node* head = convertArray2LL(arr);
    print(head);
    reorderList(head);
    print(head);
    return 0;
}