#include "iostream"
#include "vector"
using namespace std;

class Solution{
public:
    int checkPath(vector<vector<int>>& matrix){
        int r = matrix.size();
        int c = matrix[0].size();
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        int sx = 0,sy = 0,dx = 0,dy = 0;
        for(int i=0; i< r; i++){
            for(int j=0; j< c; j++){
                if(matrix[i][j] == 1){
                    sx = i; sy = j;
                }
                if(matrix[i][j] == 2){
                    dx = i; dy = j;
                }
            }
        }
        return dfs(sx, sy, dx, dy, matrix, visited);
    }
    int dfs(int sx, int sy, int dx, int dy, vector<vector<int>>& matrix, vector<vector<bool>>& visited){
        if(sx == dx && sy == dy){
            return 1;
        }
        visited[sx][sy] = true;
        pair<int, int> dis[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for(int t = 0 ; t< 4; t++){
            int sx1 = sx + dis[t].first;
            int sy1 = sy + dis[t].second;
            bool is_valid_move = sx1 >= 0 && sx1 < matrix.size() && sy1 >= 0
                    && sy1 < matrix[0].size() && !visited[sx1][sy1] && matrix[sx1][sy1] != 0;
            if(is_valid_move){
                if(dfs(sx1, sy1, dx, dy, matrix, visited) == 1){
                    return 1;
                }
            }
        }
        return 0;
    }

};
int main(){
    Solution s;
    vector<vector<int>> matrix {
            {1, 0},
            {0, 2}
    };
    cout << s.checkPath(matrix) << endl;
}

