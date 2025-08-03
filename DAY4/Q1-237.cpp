#include<bits/stdc++.h> 
using namespace std;
class ListNode {
    public:
    int val;
    ListNode* next; // node is the self defined datatype which we are storing. start bcz it stores the memory location of the next

    public:
    ListNode(int val1, ListNode* next1) {
        val = val1;
        next = next1;
    }

    public:
    ListNode(int val1) {
        val=val1;
        next=nullptr;
    }
};



class Solution {
public:
    void deleteNode(ListNode* node) {
        if (node == NULL || node->next == NULL) return;

        node->val=node->next->val;
        ListNode* temp = node->next;
        node->next=node->next->next;
        delete temp;
    }
};