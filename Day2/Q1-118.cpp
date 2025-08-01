#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> triangle;

        for (int row=0; row<n; row++) {
            vector<int> currentrow;
            int value=1;
            for (int col=0; col<=row; col++) {
                currentrow.push_back(value);
                value=value*(row-col)/(col+1);
            }
            triangle.push_back(currentrow);
        }
        return triangle;

    }
};