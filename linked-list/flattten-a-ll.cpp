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

//Brute

Node* flattenLinkedListBrute(Node* head) 
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

//Optimal

Node* merge(Node* list1, Node* list2){
	Node* dummy = new Node(-1);
	Node* res = dummy;
	while(list1 && list2){
		if(list1->data < list2->data){
			res->child = list1;
			res = list1;
			list1 = list1->child;
		}else{
			res->child = list2;
			res = list2;
			list2 = list2->child;
		}
		res->next = NULL;
	}
	if(list1) res->child = list1;
	else res->child = list2;
	if(dummy->child) dummy->child->next = nullptr;
	return dummy->child;
}

Node* flattenLinkedListOptimal(Node* head) 
{
	// Write your code here
	if(head == NULL || head->next == NULL) return head;

	Node* mergeHead = flattenLinkedList(head->next);
	head = merge(head, mergeHead);
	return head;
}