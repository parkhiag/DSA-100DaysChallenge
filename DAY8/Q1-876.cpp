#include <bits/stdc++.h> 
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

// method one to solve this problem. this uses n square time complexity.
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* temp= head;
        int count=0;
        while (temp!=NULL) {
            count++;
            temp=temp->next;

        }
        int midnode=(count/2)+1;
        temp=head;
        while (temp!=NULL) {
            midnode=midnode-1;
            if (midnode==0) {
                break;
            }
            temp=temp->next;
        }
        return temp;

    }
};

// method two. 