#include "iostream"
#include "vector"

using namespace std;

class Solution{
public:
    bool dfs(int u, int d, vector<vector<int>>& g, vector<bool>& visited) {
        if(u == d){
            return true;
        }
        visited[u] = true;
        vector<int> ad_list = g[u];
        for(int v: ad_list){
            if(!visited[v]){
                if(dfs(v, d, g, visited)){
                    return true;
                }
            }
        }
        return false;
    }
    int solve(int n, vector<vector<int>> edges){
        vector<vector<int>> g = createGraph(n, edges);
        vector<bool> visited(n, false);
        if(dfs(0, n-1, g, visited)){
            return 1;
        }
        return 0;
    }
    vector<vector<int>> createGraph(int n, vector<vector<int>> edges){
        vector<vector<int>> g(n, vector<int>());
        for(int i=0; i< edges.size(); i++){
            vector<int> edge = edges[i];
            int u = edge[0]-1;
            int v = edge[1]-1;
            g[u].push_back(v);
        }
        return g;
    }
};
int main(){
    Solution s;
    vector<vector<int>> edges = {
            {1, 2},
            {2, 3},
            {3, 4},
            {4, 5}
    };
    cout << s.solve(5, edges) << endl;
}
