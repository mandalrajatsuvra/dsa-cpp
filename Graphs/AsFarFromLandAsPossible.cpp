#include "iostream"
#include "vector"
#include "queue"
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> visited(r, vector<int>(c, 0));
        for(int i=0; i< r; i++){
            for(int j=0; j< c; j++){
                visited[i][j] = grid[i][j];
                if(grid[i][j]){
                    q.push({0, {i,j}});
                }
            }
        }
        int max_dist = -1;
        while (!q.empty()){
            int size = q.size();
            for(int i=0; i< size; i++){
                pair<int,pair<int, int>> n = q.front();
                int dist = n.first;
                pair<int, int> node = n.second;
                max_dist = max(max_dist, dist);
                q.pop();
                const pair<int, int> dir[] = {{-1,0}, {1, 0}, {0,1}, {0, -1}};
                for(int i=0; i< 4; i++){
                    int x = node.first +dir[i].first;
                    int y = node.second + dir[i].second;
                    bool is_valid = x >= 0 && x < grid.size() && y>=0 && y < grid[0].size() && visited[x][y] == 0;
                    if(is_valid){
                        visited[x][y] = true;
                        q.push({dist+1, {x, y}});
                    }
                }
            }
        }
        return max_dist == 0? -1 : max_dist;
    }
};


int main(){
    Solution s;
    vector<vector<int>> grid {
            {1,0,1},
            {0,0,0},
            {1,0,1}
    };
    cout << s.maxDistance(grid) << endl;


}