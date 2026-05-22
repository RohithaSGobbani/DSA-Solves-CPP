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

Node* convert(vector<int> &arr){
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

Node* mergeKLists(vector<Node*>& lists) {
    int n = lists.size();
    vector<int> arr;
    for(int i = 0; i < n; i++){
        Node* t = lists[i];
        while(t){
            arr.push_back(t->data);
            t = t->next;
        }
    }
    sort(arr.begin(), arr.end());
    Node* head = convert(arr);
    return head;
}


int main() {
    vector<int> arr1 = {1, 4, 5};
    vector<int> arr2 = {1, 3, 4};
    vector<int> arr3 = {2, 6};

    Node* list1 = convert(arr1);
    Node* list2 = convert(arr2);
    Node* list3 = convert(arr3);

    vector<Node*> lists = {list1, list2, list3};

    Node* mergedListHead = mergeKLists(lists);


    cout << "Merged List: ";
    print(mergedListHead);

    return 0;
}