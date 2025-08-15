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

// method 2 : 

