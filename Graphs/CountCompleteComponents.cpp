#include "iostream"
#include "vector"
#include "string"
#include "queue"

using namespace std;


class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> g[n];
        vector<bool> visited(n, false);
        for(vector<int>& edge: edges){
            int u = edge[0];
            int v = edge[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int cnt = 0;
        for(int i=0; i< n; i++){
            if(!visited[i]){
                 if(bfs(i, g, visited)){
                    cnt ++;
                 }
            }
        }
        return cnt;
    }
    bool bfs(int u,  vector<int> g[], vector<bool>& visited){
        int n = 0;
        queue<int> q;
        q.push(u);
        visited[u] = true;
        int e = 0;
        while (!q.empty()){
            int node = q.front();
            e += g[node].size();
            n++;
            q.pop();
            vector<int> adList = g[node];
            for(int v: adList){
                if(!visited[v]){
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        if(e == n*(n-1)){
            return true;
        }
        return false;
    }


};