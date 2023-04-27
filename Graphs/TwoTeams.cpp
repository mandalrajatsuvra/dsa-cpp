#include "iostream"
#include "vector"
using namespace std;

class Solution{
public:
    int solve(int n, vector<vector<int>>& edges){
        vector<int> teams(n, -1);
        vector<int> g[n];
        for(int i=0; i< edges.size(); i++){
            vector<int> edge = edges[i];
            int u = edge[0]-1;
            int v = edge[1]-1;
            g[u].push_back(v);
        }
        for(int i=0; i< n; i++){
            if(teams[i] == -1) {
               if( dfs(i, 0, g, teams) == 0){
                   return 0;
               }
            }
        }
        return 1;
    }
    int dfs(int u, int c,  vector<int> g[], vector<int>& teams){
        teams[u] = c;
        vector<int> ad_list = g[u];
        for(int v: ad_list){
            if(teams[v]== -1){
                if(dfs(v, 1-c, g, teams) == 0){
                    return 0;
                }
            }else if(teams[v] == c){
                return 0;
            }
        }
        return 1;
    }
};
int main(){
    Solution s;
    vector<vector<int>> edges{
            {1, 2},
            {2, 3},
            {1, 5},
            {2, 4}
    };
    cout << s.solve(5,edges) << endl;
    vector<vector<int>> edges2 {
            {1, 4},
            {3, 1},
            {4, 3},
            {2, 1}
    };
    cout << s.solve(4, edges2) << endl;
}
