#include "iostream"
#include "vector"
using namespace std;


enum  Color{
    WHITE,
    GRAY,
    BLACK
};
class Solution {
public:
    bool hasCycleExists;
    bool validTree(int n, vector<vector<int>>& edges) {
        hasCycleExists = false;
        vector<int> g[n];
        for(int i=0; i< edges.size(); i++){
            vector<int> edge = edges[i];
            int u = edge[0];
            int v = edge[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<Color> colors(n , WHITE);
        int cc = 0;
        for(int i=0; i< n; i++){
            if(colors[i] == WHITE){
                hasCycle(0, -1, g, colors);
                if(hasCycleExists){
                    return false;
                }
                cc++;
            }
        }
        return  cc > 1 ? false: true;
    }
    void hasCycle(int u, int prev,  vector<int> g[], vector<Color> colors){
        colors[u] = GRAY;
        vector<int> adList = g[u];
        for(int v: adList){
            if(colors[v] != BLACK &&  v != prev){
                if(colors[v] == GRAY){
                    hasCycleExists = true;
                }else {
                    hasCycle(v, u, g, colors);
                }
            }
        }
        colors[u] = BLACK;
    }
};

//Question https://leetcode.com/problems/graph-valid-tree/