#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {

        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> dp(r, vector<int>(c, 0));

        pair<int, int> dis[] = {{0, -1}, {1, -1}, {-1, -1}};
        for(int j=1; j < c; j++){
            for(int i=0; i< r; i++){
                for(int k=0; k< 3; k++){
                    int x = i + dis[k].first;
                    int y = j + dis[k].second;
                    if( x>= 0 && x < r && y >=0 && y < c){
                        if(grid[i][j] > grid[x][y]){
                            if(dp[x][y] == j-1) {
                                dp[i][j] = max(dp[i][j], dp[x][y] + 1);
                            }
                        }
                    }
                }
            }
        }
        int maxi = INT_MIN;
        for(int i = 0; i < r; i++){
            for(int j=0; j< c; j++) {
                maxi = max(maxi, dp[i][j]);
            }
        }
        return maxi;
    }
};