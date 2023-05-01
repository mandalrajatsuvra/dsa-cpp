#include "iostream"
#include "vector"
using namespace std;
class Solution {
public:
    long long dfs(int u, vector<int> g[], vector<bool>& visited){
        visited[u] = true;
        vector<int> ad_list = g[u];
        long long cnt = 1;
        for(int v: ad_list){
            if(!visited[v]){
               cnt += dfs(v, g, visited);
            }
        }
        return cnt;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> g[n];
        for(int i=0; i< edges.size(); i++){
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n, false);
        long long nodes = n;
        long long total_pairs = 0;
        long long cc_size = 0;
        for(int i=0; i< n; i++){
            if(!visited[i]){
                cc_size = dfs(i, g, visited);
                total_pairs += cc_size * (nodes - cc_size);
                nodes -= cc_size;
            }
        }
        return total_pairs;
    }
};

int main(){
    Solution s;
    vector<vector<int>> edges {
            {0, 1},
            {0, 2},
            {1, 2}
    };
    cout<< s.countPairs(3, edges) << endl;

}
