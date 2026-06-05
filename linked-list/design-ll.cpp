class MyLinkedList {
public:
    struct Node{
        int val;
        Node* next;
        Node(int data){
            val = data;
            next = nullptr;
        }
    };

    Node* head;

    MyLinkedList() {
        head = nullptr;
    }
    
    int get(int index) {
        if(index < 0) return -1;
        int i = 0;
        Node* temp = head;
        while(i < index && temp){
            temp = temp->next;
            i++;
        }
        if(temp) return temp->val;
        else return -1;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0) return;
        int i = 0;
        Node* newNode = new Node(val);
        Node* temp = head;
        if(index == 0){
            addAtHead(val);
            return;
        }
        while(i < index-1 && temp && temp->next){
            i++;
            temp = temp->next;
        }
        if(temp){
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    
    void deleteAtIndex(int index) {
        if(index < 0) return;
        int i = 0;
        Node* temp = head;
        if(index == 0){
            Node* d = head;
            if(head) head = head->next;
            delete d;
            return;
        }
        while(i < index-1 && temp && temp->next){
            temp = temp->next;
            i++;
        }
        Node* d = temp->next;
        if(d) temp->next = d->next;
        delete d;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */