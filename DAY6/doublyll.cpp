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

int main() {
    vector<int> arr= {1,3,2,4};
    Node* head = arrtoDLL(arr);
    print(head);

    return 0;
}