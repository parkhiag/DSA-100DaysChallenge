#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
         
        int sum=0; 
        int i=0;
        int maxsum=INT_MIN;

        while (i<n) {
            sum+=nums[i];
            maxsum=max(maxsum,sum);
            if (sum<0) {
                sum=0;
            }
            i++;
        }
        return maxsum;
    }
};