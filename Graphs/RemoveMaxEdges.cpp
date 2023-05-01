#include "iostream"
#include "vector"
#include "unordered_map"
using namespace std;

class UnionFind{
private:
    vector<int> parent;
    vector<int> size;
public:
    UnionFind(int n): parent(n), size(n){
        for(int i=0; i< n ; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int find(int u){
        if(parent[u] == u){
            return u;
        }
        parent[u] = find(parent[u]);
        return parent[u];
    }
    bool connected(int u, int v){
        return find(u) == find(v);
    }
    void make_union(int u, int v){
        int setx = find(u);
        int sety = find(v);
        if(setx == sety){
            return;
        }
        if(size[setx] > size[sety]){
            parent[sety] = setx;
            size[setx] += size[sety];
        }else{
            parent[setx] = sety;
            size[sety] += size[setx];
        }
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UnionFind bob{n};
        UnionFind alice{n};
        int rc = 0;
        for(int i =0; i< edges.size(); i++){
            vector<int> edge = edges[i];
            int t = edge[0];
            int u = edge[1] - 1;
            int v = edge[2] - 1;
            if(t == 3){
                if(bob.connected(u,v) && alice.connected(u, v)){
                   rc++;
                }else{
                    bob.make_union(u,v);
                    alice.make_union(u,v);
                }
            }
        }
        for(int i =0; i< edges.size(); i++){
            vector<int> edge = edges[i];
            int t = edge[0];
            int u = edge[1] - 1;
            int v = edge[2] - 1;
            if(t == 1){
                if(bob.connected(u,v)){
                    rc++;
                }else{
                    bob.make_union(u,v);
                }
            }else if(t == 2){
                if(alice.connected(u,v)){
                    rc ++;
                }else{
                    alice.make_union(u,v);
                }
            }
        }
        for(int i = 1; i <= n-1; i++){
            if(!bob.connected(0, i) || !alice.connected(0,i)){
                return -1;
            }
        }
        return rc;
    }
};
int main(){
    Solution s;
    vector<vector<int>> edges {
            {3,1,2},
            {3,2,3},
            {1,1,3},
            {1,2,4},
            {1,1,2},
            {2,3,4}
    };
    cout << s.maxNumEdgesToRemove(4,edges) << endl;
    vector<vector<int>> edges2{
            {3,1,2},
            {3,2,3},
            {1,1,4},
            {2,1,4}
    };
    cout << s.maxNumEdgesToRemove(4, edges2) << endl;

    vector<vector<int>> edges3{
            {3,2,3},
            {1,1,2},
            {2,3,4}
    };

    cout << s.maxNumEdgesToRemove(4, edges3) << endl;

    vector<vector<int>> edges4{
            {2,1,2}
    };
    cout << s.maxNumEdgesToRemove(2, edges4) << endl;
}
