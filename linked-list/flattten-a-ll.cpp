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

Node* flattenLinkedList(Node* head) 
{
	vector<int> arr;
	Node* temp = head;
	while(temp){
		Node* t2 = temp;
		while(t2){
			arr.push_back(t2->data);
			t2 = t2->child;
		}
		temp = temp->next;
	}
	sort(arr.begin(), arr.end());
	head = convert2LL(arr);
	return head;
}
