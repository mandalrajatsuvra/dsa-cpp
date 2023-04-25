/*Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will take to reach the target position.If it cannot reach the target position return -1.

Note:
The initial and the target position co-ordinates of Knight have been given accoring to 1-base indexing.

Example 1:

Input:
N=6
knightPos[ ] = {4, 5}
targetPos[ ] = {1, 1}
Output:
3
Explanation:

Knight takes 3 step to reach from
        (4, 5) to (1, 1):
(4, 5) -> (5, 3) -> (3, 2) -> (1, 1).

Example 2:

Input:
N=8
knightPos[ ] = {7, 7}
targetPos[ ] = {1, 5}
Output:
4
Explanation:
Knight takes 4 steps to reach from
        (7, 7) to (1, 5):
(4, 5) -> (6, 5) -> (5, 3) -> (7, 2) -> (1, 5).*/

#include "iostream"
#include "vector"
#include "queue"

using namespace std;

class Solutions{
public:
    int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int n){
        vector<vector<bool>> cb(n, vector<bool>(n, false));
        int sx = n - KnightPos[1];
        int sy = KnightPos[0]-1;
        int ex = n- TargetPos[1];
        int ey = TargetPos[0]-1;
        return bfs(sx, sy, ex, ey, cb, n);
    }
    int bfs(int sx, int sy , int ex ,int ey, vector<vector<bool>>& visited, int n){
        queue<pair<int, pair<int, int>>> q;
        pair<int, pair<int, int>> s ={0, {sx, sy}};
        q.push(s);
        visited[sx][sy] = true;
        while (!q.empty()){
            pair<int ,pair<int, int>> node = q.front();
            q.pop();
            int steps = node.first;
            pair<int,int> pos = node.second;
            if(pos.first == ex && pos.second == ey){
                return steps;
            }
            pair<int, int> dis[] =  { {-2,1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
            for(int i=0; i< 8; i++){
                int sx1 = pos.first + dis[i].first;
                int sy1 = pos.second + dis[i].second;
                bool is_valid = sx1 >= 0 && sx1 <n && sy1 >= 0 && sy1 < n && !visited[sx1][sy1];
                if(is_valid){
                    visited[sx1][sy1] = true;
                    q.push({steps+1, {sx1, sy1}});
                }
            }

        }
        return -1;
    }
};
int main(){
    Solutions s;
    vector<int> sp {3 ,3};
    vector<int> ep{2, 1};
    cout<< s.minStepToReachTarget(sp, ep, 3);
}


















