#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int r = costs.size();
        int c = costs[0].size();
        vector<vector<int>> dp(r, vector<int>(c, 0));
        for(int i=0; i< c; i++){
            dp[0][i] = costs[0][i];
        }
        for(int i=1; i< r; i++){
            for(int j=0; j< c; j++){
                int mini = INT_MAX;
                for(int k=0; k< c; k++){
                    if(k != j){
                        mini = min(mini, dp[i-1][k]);
                    }
                }
                dp[i][j] = costs[i][j] + mini;
            }
        }
        int mini = dp[r-1][0];
        for(int i=1; i< c; i++){
            mini = min(mini, dp[r-1][i]);
        }
        return mini;
    }
};
int main(){
    Solution s;
    vector<vector<int>> vt {
            {17,2,17},
            {16,16,5},
            {14,3,19}
    };
    cout << s.minCost(vt);
}



