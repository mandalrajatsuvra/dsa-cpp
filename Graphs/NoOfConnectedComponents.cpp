#include "iostream"
#include "vector"
#include "unordered_set"
using namespace std;

class UnionBySize{
private:
    vector<int> parent;
    vector<int> size;
public:
    UnionBySize(int n): parent(n), size(n){
        for(int i=0; i< n ; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int find(int u){
        if(parent[u] == u){
            return parent[u];
        }
        parent[u] = find(parent[u]);
        return parent[u];
    }
    bool connected(int u, int v){
        return find(u) == find(v);
    }
    void union_make(int u, int v){
        int uset = find(u);
        int vset = find(v);
        if(uset == vset){
            return;
        }
        if(size[uset] > size[vset]){
            parent[vset] = uset;
            size[uset] += size[vset];
        }else{
            parent[uset] = vset;
            size[vset] += size[uset];
        }
    }
};
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionBySize uf{n};
        for(int i=0; i< edges.size(); i++){
            uf.union_make(edges[i][0], edges[i][1]);
        }
        unordered_set<int> st;
        for(int i=0; i< n; i++){
           int root = uf.find(i);
           st.insert(root);
        }
        return st.size();
    }
};

// Question: https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/