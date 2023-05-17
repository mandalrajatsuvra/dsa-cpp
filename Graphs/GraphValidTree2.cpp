#include "iostream"
#include "vector"
#include "stack"
#include "unordered_set"
using namespace std;

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> g[n];
        for(int i=0; i< edges.size(); i++){
            vector<int> edge = edges[i];
            int u = edge[0];
            int v = edge[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        // DFS using stack iterative approach
        stack<pair<int, int>> stk;
        stk.push({0, -1});
        unordered_set<int> visited;
        visited.insert(0);
        while (!stk.empty()){
            pair<int, int> node = stk.top();
            stk.pop();
            for(int v: g[node.first]){
                if(v != node.second){
                    if(visited.find(v) != visited.end()){
                        return false;
                    }else{
                        visited.insert(v);
                        stk.push({v, node.first});
                    }
                }
            }
        }
        return visited.size() == n;
    }
};

//Question https://leetcode.com/problems/graph-valid-tree/