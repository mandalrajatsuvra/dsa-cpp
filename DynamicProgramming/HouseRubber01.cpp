#include "iostream"
#include "vector"
using namespace std;

// Correct Solution

class Solution {
public:
    int rob(vector<int>& nums) {
        int l = nums.size();
        vector<vector<int>> dp(l+1, vector<int>(2, -1));
        return max(solve(nums, 0, true, dp), solve(nums, 0, false, dp));
    }
    int solve(vector<int>& arr, int index, bool hasStolenPreviousHouse, vector<vector<int>>& dp){
        if(index == arr.size()){
            return 0;
        }

        if(dp[index][hasStolenPreviousHouse] != -1){
            return dp[index][hasStolenPreviousHouse];
        }

        if(hasStolenPreviousHouse){
            return dp[index][hasStolenPreviousHouse] = solve(arr, index+1, false, dp);
        }else{
            return  dp[index][hasStolenPreviousHouse] = max(
                    arr[index] + solve(arr, index+1, true, dp),
                    solve(arr, index+1, false, dp)
                    );
        }
    }
};

int main(){
    vector<int> nums = {2,7,9,3,1};
    Solution s;
    cout << s.rob(nums) << endl;
}
