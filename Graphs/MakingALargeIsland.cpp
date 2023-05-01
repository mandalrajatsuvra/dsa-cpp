#include "iostream"
#include "vector"
#include "unordered_set"
using namespace std;

class UnionFindBySize{
private:
    vector<int> parent;
    vector<int> sz;
public:
    UnionFindBySize(int n): parent(n), sz(n){
        for(int i=0; i< n ; i++){
            parent[i] = i;
            sz[i] = 1;
        }
    }
    int find(int u){
        if( u == parent[u]){
            return u;
        }
        parent[u] = find(parent[u]);
        return parent[u];
    }
    bool connected(int u, int v){
        return find(u) == find(v);
    }
    int size(int u){
        return sz[u];
    }
    void make_union(int u, int v){
        int uid = find(u);
        int vid = find(v);
        if(uid == vid){
            return;
        }
        if(sz[uid] > sz[vid]){
            parent[vid] = uid;
            sz[uid] += sz[vid];
        }else{
            parent[uid] = vid;
            sz[vid] += sz[uid];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int n = r*r;
        UnionFindBySize uf{n};
        const pair<int, int> dir[] = {{-1,0}, {1, 0}, {0, 1}, {0, -1}};
        for(int i=0; i< r; i++){
            for(int j=0; j< r; j++){
                if(grid[i][j] == 1){
                    int start = r*i + j;
                    for(int t=0; t< 4; t++){
                        int i1 = i + dir[t].first;
                        int j1 = j + dir[t].second;
                        if(i1 >= 0 && i1 < r && j1 >= 0 && j1 < r  & grid[i1][j1] == 1){
                            int end = i1*r + j1;
                            uf.make_union(start, end);
                        }
                    }
                }
            }
        }
        int maxi = uf.size(uf.find(0));
        for(int i=0; i< r; i++){
            for(int j=0; j< r; j++){
                if(grid[i][j] == 0){
                    unordered_set<int> roots;
                    for(int t=0; t< 4; t++){
                        int i1 = i + dir[t].first;
                        int j1 = j + dir[t].second;
                        if(i1 >= 0 && i1 < r && j1 >= 0 && j1 < r && grid[i1][j1] == 1){
                            int end = i1* r + j1;
                            roots.insert(uf.find(end));
                        }
                    }
                    int size = 1;
                    for(int u: roots){
                        size += uf.size(u);
                    }
                    maxi = max(maxi, size);
                }
            }
        }
        return maxi;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid {
            {1,1},{1,1}
    };
    vector<vector<int>> grid2 {
            {1, 1,0,0,1,1},
            {1, 1,0,0,1,1},
            {1, 1,0,1,1,1},
            {0, 0,0,0,0,0},
            {1, 1,1,1,1,1},
            {1, 1,1,1,1,1}
    };
    vector<vector<int>> grid3 {
            {1, 1,0,0,1,1},
            {1, 1,0,0,1,1},
            {1, 1,0,1,1,1},
            {0, 0,0,0,0,0},
            {1, 1,1,1,1,1},
            {1, 1,1,1,1,1}
    };
    cout << s.largestIsland(grid) << endl;
    cout<< s.largestIsland(grid2) << endl;
}