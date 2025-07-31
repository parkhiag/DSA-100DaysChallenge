#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0;
        int j=0;
        vector<int> ans;

        while (i<m && j<n) {
            if (nums1[i]<=nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
            }
            else {
                ans.push_back(nums2[j]);
                j++;
            }
        }
        // when elemnts in nums1 are left
        while (i<m) {
            ans.push_back(nums1[i]);
            i++;
        }
        // when elements in nums2 are left
        while (j<n) {
            ans.push_back(nums2[j]);
            j++;
        }

        for (int i=0; i<m+n; i++) {
            nums1[i]=ans[i];
        }

    }
};