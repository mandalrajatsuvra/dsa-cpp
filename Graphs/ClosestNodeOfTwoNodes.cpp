#include "iostream"
#include "vector"
#include "unordered_map"

using namespace std;

class Solution{
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<bool> visited(n, false);
        vector<int> v1;
        vector<int> v2;
        dfs(node1, edges, visited, v1);
        dfs(node2, edges, visited, v2);
        unordered_map<int, int> mp;
        for(int i=0; i< v1.size(); i++){
            mp[v1[i]] = i;
        }
        int dist = INT_MAX;
        int res = INT_MAX;
        for(int i=0; i< v2.size(); i++){
            if(mp.find(v2[i]) != mp.end()){
                int t = max(i, mp[v2[i]]);
                if(t < dist){
                    res = v2[i];
                    dist = t;
                }else if(t == dist){
                    res = min(res, v2[i]);
                }
            }
        }
        return res==INT_MAX ? -1: res;
    }
    void dfs(int u, vector<int>& edges, vector<bool>& visited, vector<int>& res){
        if(u == -1){
            return;
        }
        visited[u] = true;
        res.push_back(u);
        int v = edges[u];
        if(!visited[v]){
            dfs(v, edges, visited, res);
        }
        visited[u] = false;
    }
};
int main(){
    Solution s;
    vector<int> edges {2,2,3,-1};
    cout << s.closestMeetingNode(edges, 0, 1) << endl;

    vector<int> edges2 {1,2,-1};
    cout << s.closestMeetingNode(edges2, 0, 2) << endl;

}