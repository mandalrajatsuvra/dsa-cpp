#include "iostream"
#include "vector"
#include "queue"
using namespace std;

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        int maxi = 0;
        for(int i=0; i< r; i++){
            for(int j=0; j< c; j++){
                if(!visited[i][j] && grid[i][j]> 0){
                    maxi = max(maxi, bfs(i, j, grid, visited));
                }
            }
        }
        return maxi;
    }

    int bfs(int x ,int y, vector<vector<int>>& grid, vector<vector<bool>>& visited){
        pair<int, int> source = {x, y};
        queue<pair<int, int>> q;
        q.push(source);
        visited[source.first][source.second]= true;

        int fish_count = 0;
        while (!q.empty()){
            pair<int, int> n = q.front();
            q.pop();
            fish_count += grid[n.first][n.second];

            pair<int, int> dir[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            for(int i=0; i< 4; i++){
                int x1 = n.first + dir[i].first;
                int y1 = n.second + dir[i]. second;
                bool is_valid = x1 >= 0 && x1 < grid.size() && y1 >= 0 && y1 < grid[0].size()
                        && !visited[x1][y1] && grid[x1][y1] > 0;
                if(is_valid){
                    visited[x1][y1] = true;
                    q.push({x1, y1});
                }
            }
        }
        return fish_count;
    }
};



int main(){




}

