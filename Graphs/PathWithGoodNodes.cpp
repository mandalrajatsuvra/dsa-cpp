
#include "iostream"
#include "vector"

using namespace std;

class Solution{
public:
    int solve(vector<int>& good, vector<vector<int>>& edges, int c){
        int n = good.size();
        vector<int> g[n];
        for(int i=0; i< edges.size(); i++){
            vector<int> edge = edges[i];
            int u = edge[0]-1;
            int v = edge[1]-1;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<bool> visited(n, false);
        return dfs(0, good[0], g, good, c, visited);
    }
    int dfs(int u, int s, vector<int> g[], vector<int>& good, int c,  vector<bool>& visited){
        if(is_terminal_node(u, g, visited)){
            if(s <= c){
                return 1;
            }else{
                return 0;
            }
        }
        vector<int> ad_list = g[u];
        visited[u] = true;
        int cnt = 0;
        for(int v: ad_list){
            if(!visited[v]) {
                cnt += dfs(v, s + good[v], g, good, c, visited);
            }
        }
        return cnt;
    }
    bool is_terminal_node(int u, vector<int> g[], vector<bool>& visited){
        vector<int> ad_list = g[u];
        for(int node : ad_list){
            if(!visited[node]){
                return false;
            }
        }
        return true;
    }
};
int main(){
    Solution s;
    vector<int> good {1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1};
    vector<vector<int>> edges {
            {10, 6},
            {3, 2},
            {12, 7},
            {9, 5},
            {2, 1},
            {8, 3},
            {7, 1},
            {4, 2},
            {6, 3},
            {11, 4},
            {5, 3},
            {13, 11}
    };

    vector<int> good2 = {0, 1, 0, 1, 1, 1};
    vector<vector<int>> edges2 = {
            {1, 2},
            {1, 5},
            {1, 6},
            {2, 3},
            {2, 4}
    };
    cout << s.solve(good, edges, 7) << endl;
    cout << s.solve(good2, edges2, 1) << endl;
}
