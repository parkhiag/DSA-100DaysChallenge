#include <bits/stdc++.h> 
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

class Solution {
public:
    Node* removeElements(Node* head, int val) {
        while (head != nullptr && head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        if (head == nullptr) return nullptr;

        Node* curr = head;
        while (curr != nullptr && curr->next != nullptr) {
            if (curr->next->data == val) {
                Node* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            } else {
                curr = curr->next;
            }
        }

        return head;
    }
};
