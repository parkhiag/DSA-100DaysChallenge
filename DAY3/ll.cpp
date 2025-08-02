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

// converting array into linked list
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

// finding length of the linked list
int lengthofll(Node* head) {
    int cnt=0;
    Node* temp = head;
    while (temp) {
        
        temp=temp->next;
        cnt++;
    }
    return cnt;
}

// checking if a particular element is present in the linked list or not
int checkIFpresent(Node* head, int val) {
    Node* temp=head;
    while (temp) {
        if (temp->data == val) return 1;
        temp=temp->next;
    }
    return 0;
}

// deleting a node 
Node* deletehead(Node* head) {
    if (head==NULL) return head;
    Node* temp= head;
    head=head->next;
    delete temp;
    return head;
}

// printing the linked list
Node* print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return head;
}


// deleting the tail of the linkedlist
Node* deletetail(Node* head) {
    Node* temp=head;
    if (head==NULL || head->next == NULL) return NULL;
    while (temp->next->next!=NULL) {
        temp=temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    return head;
}

int main() {
    vector<int> arr = {2, 5, 8, 7};
    Node* head = convertArr2LL(arr);
/*  Node* temp = head; // traversing in a linked list
    while (temp) {
        cout << temp->data << " ";
        temp=temp->next; // we move temp to the place which was stored in temp's next
    }
 */
   // cout << lengthofll(head);
   // cout << checkIFpresent(head, 8);
   head= deletetail(head);
   print(head);
    
     

}