
#include <cmath>
#include "iostream"
#include "vector"
#include "unordered_map"
#include "unordered_set"
using namespace std;


class Solution{
public:
    long long cost = 0;
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        cost = 0;
        unordered_map<int, vector<int>> g;
        unordered_set<int> visited;
        for(int i=0; i< roads.size(); i++){
            vector<int> edge = roads[i];
            int u = edge[0];
            int v = edge[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(0, g, visited, seats);
        return cost;
    }
    bool is_leaf_node(int node, unordered_map<int, vector<int>>& g, unordered_set<int>& visited){
        vector<int> ad_list = g[node];
        for(int v: ad_list){
            if(visited.find(v) == visited.end()){
                return false;
            }
        }
        return true;
    }
    long long dfs(int u, unordered_map<int, vector<int>>& g, unordered_set<int>& visited, int seats){

        visited.insert(u);
        vector<int> ad_list = g[u];
        int count = 0;
        for(int v: ad_list){
            if(visited.find(v) == visited.end()){
                int t = dfs(v, g, visited, seats);
                int rep_count = 1 + t;
                if(rep_count% seats == 0){
                    cost += rep_count/seats;
                }else{
                    cost += 1+ rep_count/seats;
                }
                count += rep_count;
            }
        }
        return count;
    }
};



int main(){
    Solution s;
    vector<vector<int>> roads{
            {0,1},
            {0,2},
            {0,3}
    };

    cout << s.minimumFuelCost(roads, 5) << endl;

    vector<vector<int>> roads2{
            {3,1},
            {3,2},
            {1,0},
            {0,4},
            {0,5},
            {4,6}
    };
    cout<< s.minimumFuelCost(roads2, 2) << endl;


}




