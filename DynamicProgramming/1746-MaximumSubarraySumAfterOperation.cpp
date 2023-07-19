#include "iostream"
#include "vector"
using namespace std;

// Not completed

class Solution {
public:
    int maxi = INT_MIN;
    int maxSumAfterOperation(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n +1 , vector<int>(2, INT_MIN));
    }
    int f(vector<int>&arr, int i, bool squared , vector<vector<int>> &dp){
        if(squared && i == arr.size()){
            return 0;
        }
        if(dp[i][squared] != INT_MIN){
            return dp[i][squared];
        }
        if(squared){
            int t = arr[i] + f(arr, i+1, true, dp);
            maxi = max(maxi, t);
            return dp[i][true] = maxi;
        }else {
            int tmp = max(
                    arr[i] * arr[i] + f(arr, i + 1, true, dp),
                    arr[i] + f(arr, i + 1, false, dp));
            dp[i][squared] = max(maxi, tmp);
            return dp[i][squared];
        }
    }
};

int main(){


}