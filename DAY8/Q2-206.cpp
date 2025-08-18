#include <bits/stdc++.h> 
using namespace std;

// method 1 : using a stack to first store the data and then putting it back in
// the linked list.

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        stack<int> st;

        while (temp != NULL) {
            st.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while (temp != NULL) {
            temp->val = st.top();
            st.pop();
            temp = temp->next;
        }
        return head;
    }
};

// method 2 : using iteration and no extra space


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head==NULL) return NULL;

        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* front = NULL;
        while (temp!=NULL) {
            front = temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
};

// method 3 : using recursion
class Solution {
public:

    ListNode* reverseList(ListNode* head) {
        // taking the base case. 
        if (head==NULL || head->next == NULL) {
            return head;
        }

        ListNode* newhead = reverseList(head->next);
        ListNode* front = head->next;
        front->next=head;
        head->next=NULL;
        return newhead;

    }
};

