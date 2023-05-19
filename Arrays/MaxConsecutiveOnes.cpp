#include "iostream"
#include "vector"
using namespace std;


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ones = 0;
        int maxi = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                ones++;
                maxi = max(maxi, ones);
            } else {
                ones = 0;
            }
        }
        return maxi;
    }
};