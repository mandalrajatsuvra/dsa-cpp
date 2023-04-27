#include "iostream"
#include "vector"
using namespace std;

class Solution{
public:
    int minCost(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        vector<vector<int>> dp(r, vector<int>(c, -1));
        return dfs(0,0, r-1, c-1, grid, visited, dp);
    }
    int dfs(int sx, int sy, int dx , int dy, vector<vector<int>>& grid, vector<vector<bool>>& visited, vector<vector<int>>& dp){
        if(sx == dx && sy == dy){
            return 0;
        }
        if(dp[sx][sy] != -1){
            return dp[sx][sy];
        }
        visited[sx][sy] = true;
        pair<int, int> dis[] = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};
        int min_cost = 1e6;
        for(int i=0; i< 4; i++){
            int sx1 = sx + dis[i].first;
            int sy1 = sy + dis[i].second;
            bool is_valid_move = sx1 >= 0 && sx1 < grid.size() && sy1 >= 0
                    && sy1 < grid[0].size() && !visited[sx1][sy1];
            if(is_valid_move){
                if(i == grid[sx][sy]-1){
                    int cost = dfs(sx1, sy1, dx, dy, grid, visited, dp);
                    min_cost = min(min_cost, cost);
                }else{
                    int cost = 1 + dfs(sx1, sy1, dx, dy, grid, visited, dp);
                    min_cost = min(min_cost, cost);
                }
            }
        }
        visited[sx][sy] = false;
        return dp[sx][sy] = min_cost;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid {
            {1,1,1,1},
            {2,2,2,2},
            {1,1,1,1},
            {2,2,2,2}
    };
    cout << s.minCost(grid) << endl;

    vector<vector<int>> grid2 {
            {1,1,3},
            {3,2,2},
            {1,1,4}
    };
    cout << s.minCost(grid2) << endl;
}



