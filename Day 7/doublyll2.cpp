#include<bits/stdc++.h> 
using namespace std;
class Node {
    public:
    int data;
    Node* next; // node is the self defined datatype which we are storing. start bcz it stores the memory location of the next
    Node* back;
    public:
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }

    public:
    Node(int data1) {
        data=data1;
        next=nullptr;
        back=nullptr;
    }
};

// converting array into a doubly linked list
Node* arrtoDLL(vector<int> &arr) {
    Node* head= new Node(arr[0]);
    Node* prev= head;
    for (int i=1; i<=arr.size()-1; i++) {
        Node* temp = new Node (arr[i], NULL, prev);
        prev->next=temp;
        prev=temp;
        
    }
    return head;
}

// printing a linked list
void print(Node* head) {
    while (head!=NULL) {
        cout << head->data << " ";
        head=head->next;
    }
}
// deleting a head in a doubly linked list
Node* deletehead(Node* head) {
    // case when linked list is empty
    if (head==NULL || head->next==NULL) return NULL; 
    Node* prev=head;
    head=head->next;
    head->back=NULL;
    prev->next=NULL;
    delete prev;
    return head;
}
// deleting the tail of the linked list
Node* deletetail(Node* head) {
    if (head==NULL || head->next==NULL) return head;
    Node* temp=head;
    while (temp->next!=NULL) {
        temp=temp->next;
    }
    Node* prev=temp->back;
    prev->next=NULL;
    temp->back=NULL;
    delete temp;
    return head;
}
// deleting the kth element of the doubly linked list
Node* deletek(Node* head, int k) {
    int count=0;
    Node* temp=head;
    while (temp!=NULL) {
        count++;
        if (count==k) break;
        temp=temp->next;
    }
    Node* prev=temp->back;
    Node* front=temp->next;
    if (prev==NULL && front==NULL) {
        delete temp;
        return NULL;
    }
    else if (prev==NULL) deletehead(head); // temp is at head
    else if (front==NULL) deletetail(head); // temp is at tail
    else {
        prev->next=front;
        front->back=prev;
        temp->next=NULL;
        temp->back=NULL;
        return head;
    }
    
}
// deleting a given node
void deletenode(Node* temp) {
    Node* prev=temp->back;
    Node* front=temp->next;

    if (front==NULL) {
        // we are at the tail
        prev->next=NULL;
        temp->back= temp->next= NULL;
        delete temp;
        return;
    }
    prev->next=front;
    front->back=prev;
    temp->back= temp->next= NULL;
    delete temp;
    return;
}

int main() {
    vector<int> arr= {1,3,2,4};
    Node* head = arrtoDLL(arr);
    deletenode(head->next->next);
    print(head);

    return 0;
}