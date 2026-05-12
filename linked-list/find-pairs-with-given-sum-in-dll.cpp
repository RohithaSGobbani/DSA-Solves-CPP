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

vector<pair<int, int>> findPairs(Node* head, int k)
{
    Node* t1 = head;
    vector<pair<int, int>> ans;
    while(t1 != NULL){
        Node* t2 = t1->next;

        while(t2 != NULL && (t1->data + t2->data) <= k){
            int sum = 0;
            sum += t1->data + t2->data;
            if(sum == k) ans.push_back({t1->data, t2->data});
            t2 = t2->next;
        }
        t1 = t1->next;
    }
    return ans;
}


vector<pair<int, int>> findPairsOptimal(Node* head, int k)
{
    // Write your code here.
    Node* left = head;
    Node* right = head;
    vector<pair<int, int>> ans;
    while(right->next != NULL) right = right->next;
    while(left->data < right->data){
        if((left->data + right->data) == k) {
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->back;
            };
        if((left->data + right->data) < k) left = left->next;
        if((left->data + right->data) > k) right = right->back;
    }
    return ans;
}

int main(){
    vector<int> arr = {1,2,3,4,9};
    Node* head = convertArray2DLL(arr);
    print(head);
    vector<pair<int, int>> pair = findPairsOptimal(head, 5);
    cout << endl;
    for(auto &a: pair){
        cout << a.first << " " << a.second << endl;
    }
    return 0;
}