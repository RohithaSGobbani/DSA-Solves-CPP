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

vector<int> nextLargerNodes(Node* head) {
    Node* t = head;
    int n = 0;
    while(t){
        n++;
        t = t->next;
    }
    t = head;
    vector<int> ans(n, 0);
    int i = 0;
    while(t){
        Node* temp = t;
        while(temp){
            if(temp->next && t->data < temp->next->data){
                ans[i] = (temp->next->data);
                break;
            }
            temp = temp->next;
        }
        t = t->next;
        i++;
    }
    return ans;
}

/*
Input: head = [2,7,4,3,5]
Output: [7,0,5,5,0]
*/

int main(){
    vector<int> arr = {2,7,4,3,5};
    Node* head = convertArray2LL(arr);
    print(head);
    arr = nextLargerNodes(head);
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    return 0;
}