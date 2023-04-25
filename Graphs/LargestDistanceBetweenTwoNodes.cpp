#include "iostream"
#include "vector"
#include "unordered_map"

using namespace std;

class Solution{

public:
    int solve(vector<int>& tree){
        int root = 0;
        int n = tree.size();
        unordered_map<int, vector<int>> g;
        vector<bool> visited(n, false);
        for(int i=0; i< tree.size(); i++){
            if(tree[i] == -1){
                root  = i;
            }
            g[tree[i]].push_back(i);
        }
    }
    int dfs(int u, unordered_map<int, vector<int>>& g, vector<bool>& visited){
        vector<int> ad_list = g[u];
        if(ad_list.empty()){
            return 0;
        }
        visited[u] =true;
        int t =0;
        for(int v: ad_list){
            if(!visited[v]){
               int t = 1 + dfs(v, g, visited);
               
            }
        }
        return t;
    }

};
int main(){




}
