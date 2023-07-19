#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        return min(solve(cost, 0, dp), solve(cost, 1, dp));
    }
    int solve(vector<int>& cost, int index, vector<int>& dp){
        if(index >= cost.size()){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        return dp[index]  = min(
                cost[index] + solve(cost, index+1, dp),
                cost[index] + solve(cost, index+2, dp)
                );
    }
};
int main(){
    Solution s;
    vector<int> vt = {1,100,1,1,1,100,1,1,100,1};
    cout << s.minCostClimbingStairs(vt) << endl;
}
