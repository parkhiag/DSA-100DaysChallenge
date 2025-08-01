#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int row) {
        vector<int> nthrow;
        long long value=1;

        for (int col=0; col<=row; col++) {
            nthrow.push_back(value);
            value=value*(row-col)/(col+1);
        }
        return nthrow;
    }
};