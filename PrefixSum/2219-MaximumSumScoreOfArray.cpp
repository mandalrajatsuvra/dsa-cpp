#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    long long maximumSumScore(vector<int>& nums) {
        int len = nums.size();
        vector<long long> prefix(len+1, 0);
        for(int i=1; i<= len ;i++){
            prefix[i] = nums[i-1] + prefix[i-1];
        }
        int maxi = LONG_LONG_MIN;
        for(int i=1; i<= len; i++){
            int maxVal = max(prefix[i], prefix[len]-prefix[i-1]);
            maxi = max(maxVal, maxi);
        }
        return maxi;
    }
};