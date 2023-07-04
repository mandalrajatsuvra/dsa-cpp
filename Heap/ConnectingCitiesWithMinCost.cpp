#include "iostream"
#include "vector"
#include "string"
#include "queue"
using namespace std;

struct Edge{
    int s;
    int e;
    int w;
    Edge(int start, int end, int weight): s{start}, e{end}, w{weight}{}
};

class UnionFind{
private:
    vector<int> parent;
    vector<int> size;
public:
    UnionFind(int n):parent(n), size(n){}
    int find(int u){
        if(parent[u] == u){
            return parent[u];
        }
        parent[u] = find(parent[u]);
        return parent[u];
    }
    int connected(int u, int v){
        return find(u) == find(v);
    }
    void make_union(int u, int v){
        int pu = find(u);
        int pv = find(v);
        if(pu == pv){
            return;
        }
        if(size[pu] > size[pv]){
            parent[pv] = pu;
            size[pu] += size[pv];
        }else{
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
};

class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        auto cmp = [](Edge e1, Edge e2){
            return e1.w >= e2.w;
        };
        priority_queue<Edge, vector<Edge>, decltype(cmp)>   minHeap{cmp} ;
        for(int i=0; i< connections.size(); i++){
            vector<int> edge = connections[i];
            int u = edge[0]-1;
            int v = edge[1]-1;
            int w = edge[2];
            Edge e{u, v, w};
            minHeap.push(e);
        }
        vector<Edge> mst;
        UnionFind uf{n};
        int total= 0;
        while(!minHeap.empty()){
            Edge e = minHeap.top();
            minHeap.pop();
            if(!uf.connected(e.s, e.e)){
                uf.make_union(e.s, e.e);
                mst.push_back(e);
                total += e.w;
            }
        }
       return mst.size() == n-1 ? total: -1;
    }
};