#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int len = nums.size();
        vector<int> prefix(len + 2, 0);
        for(int i=1; i<= len; i++){
            prefix[i] += prefix[i-1];
        }

        for(int i=1; i<= len; i++){
            if(prefix[i-1] == prefix[len] - prefix[i]){
                return i - 1;
            }
        }
        return -1;
    }
};
