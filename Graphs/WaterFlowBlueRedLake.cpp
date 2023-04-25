#include "iostream"
#include "vector"
#include "queue"
using namespace std;

class Solution{

public:
    pair<bool, bool> dfs(int sx, int sy, vector<vector<int>>& board,
                vector<vector<bool>>& visited, vector<vector<pair<int, int>>>& status ){
        visited[sx][sy] = true;
        pair<int, int> dis[] = {{-1,0}, {0, -1}, {0,1}, {1,0}};
        pair<int, int> sts = {false, false};
        for(int i=0; i< 4; i++){
            int sx1 = sx + dis[i].first;
            int sy1 = sy + dis[i].second;

            bool is_valid = sx1 >= 0 && sx1 < board.size() && sy1 >= 0
                    && sy1 < board[0].size() && !visited[sx1][sy1]
                    && board[sx1][sy1] >= board[sx][sy];
            if(is_valid){
                pair<int, int> t = dfs(sx1, sy1, board, visited, status);
                sts = {sts.first || t.first , sts.second || t.second};
            }else if(sx1 < 0 || sy1 < 0 ){
                sts = {true, sts.second|| status[sx][sy].second};
            }else if(sx1 >= board.size() || sy1 >= board[0].size()){
                sts = {sts.first || status[sx][sy].first, true};
            }else if(visited[sx1][sy1] == true && board[sx1][sy1] <= board[sx][sy]){
                pair<int, int> tmp = status[sx1][sy1];
                sts =  {sts.first || tmp.first , sts.second || tmp.second };
            }else{
                sts = { sts.first || false, sts.second || false};
            }

        }
        status[sx][sy] = sts;
        return sts;
    }
    int solve(vector<vector<int>> &boards){
        int r = boards.size();
        int c = boards[0].size();
        vector<vector<pair<int, int>>> status(r, vector<pair<int, int>>(c, {false, false}));
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        int total = 0;
        for(int i=0; i< r; i++){
            for(int j=0; j< c; j++){
                if(!visited[i][j]){
                    dfs(i,j, boards, visited, status);
                }
            }
        }
        for(int i=0; i< r; i++){
            for(int j=0; j< c; j++){
                if(status[i][j].first == true && status[i][j].second == true){
                    total ++;
                }
            }
        }
        return total;
    }
};
int main(){
    Solution s;
    vector<vector<int>> board = {
            {1, 2, 2, 3, 5},
            {3, 2, 3, 4, 4},
            {2, 4, 5, 3, 1},
            {6, 7, 1, 4, 5},
            {5, 1, 1, 2, 4}
    };
    vector<vector<int>> board2 = {
            {2, 2},
            {2, 2}
    };
    cout << s.solve(board2) << endl;


}


