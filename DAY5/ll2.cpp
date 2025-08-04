#include<bits/stdc++.h> 
using namespace std;
class Node {
    public:
    int data;
    Node* next; // node is the self defined datatype which we are storing. start bcz it stores the memory location of the next

    public:
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    public:
    Node(int data1) {
        data=data1;
        next=nullptr;
    }
};
Node* convertArr2LL(vector<int> &arr) { // we cannot return entire ll so we return the head
    Node* head= new Node (arr[0]); // head will always be the first element. head points to arr[0].
    Node* mover=head; // mover is pointing to the head
    for (int i=1; i<arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp; // mpehle we made mover then temp and now this code links them both. it says mover ka text points to temp
        mover=temp; // also we can se mover=mover.next
    }
    return head;
}
Node* print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return head;
}

// inserting an element as head

// we'll create a new node. put the element which we want to add in that node. then call it as temp. make the next of this temp as the current head. and now alling this new node as head.

Node* inserthead(Node* head, int value) {
    Node* temp = new Node (value , head);
    return temp;
}

Node* insertTail(Node* head, int value) {
    // first we will shift the temp to the end.
    if (head==NULL) return new Node(value, NULL);
    Node* temp=head;
    while (temp->next!=NULL) {
        temp=temp->next;
    }
    temp->next= new Node(value, NULL);
    return head;
}

Node* insertAtk(Node* head, int value, int k) {
    if (head = NULL) {
        if (k==1) return new Node(value);
        else return NULL;
    }
    if (k==1) {
        Node* temp=new Node(value, head);
        return temp;
    }
    Node* temp=head;
    int count=0;
    while (temp!=NULL) {
        count++;
        if (count==k-1) {
            Node* x=new Node(value, temp->next);
            temp->next=x;
            break;
        }
        temp=temp->next;
    }
    return head;
}

int main() {
    vector<int> arr = {12, 5, 8, 7};
    Node* head = convertArr2LL(arr);
    head = insertAtk(head, 100, 3);
    print(head);

}

