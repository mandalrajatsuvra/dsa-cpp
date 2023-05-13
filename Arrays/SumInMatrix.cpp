#include "iostream"
#include "vector"
#include "string"
#include "queue"
using  namespace std;


class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int r = nums.size();
        int c = nums[0].size();
        vector<priority_queue<int>> pqs(r, priority_queue<int>());
        for(int i=0; i< r; i++){
            for(int j=0; j< c; j++){
                pqs[i].push(nums[i][j]);
            }
        }
        int res = 0;
        for(int j=0; j< c; j++){
            int maxi = INT_MIN;
            for(int i=0; i< r; i++){
                maxi = max(maxi, pqs[i].top());
                pqs[i].pop();
            }
            res += maxi;
        }
        return  res;
    }
};