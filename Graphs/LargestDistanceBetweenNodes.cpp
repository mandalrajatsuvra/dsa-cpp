#include "iostream"
#include "vector"
#include "unordered_map"
#include "queue"

using namespace std;

class Solution{
public:
    int ans = 0;
    int solve(vector<int>& tree){
        ans = 0;
        int n = tree.size();
        unordered_map<int, vector<int>> mp;
        int root = 0;
        for(int i=0; i< tree.size(); i++){
            if(tree[i] == -1){
                root = i;
            }
            mp[tree[i]].push_back(i);
        }
        vector<bool> visited(n, false);
        dfs(root, mp, visited);
        return ans;
    }
    int dfs(int u, unordered_map<int, vector<int>>& g, vector<bool>& visited){
        vector<int> ad_list = g[u];
        if(ad_list.empty()){
            return 0;
        }
        visited[u] = true;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int v: ad_list){
            if(!visited[v]){
                int t = 1 + dfs(v, g, visited);
                if(minHeap.size() < 2){
                    minHeap.push(t);
                }else if(t > minHeap.top()){
                    minHeap.pop();
                    minHeap.push(t);
                }
            }
        }
        if(minHeap.size() == 0){
            return 0;
        }else if(minHeap.size() == 1){
            ans = max(ans, minHeap.top());
            return minHeap.top();
        }else{
            int m1 = minHeap.top();
            minHeap.pop();
            int m2 = minHeap.top();
            minHeap.pop();
            ans = max(ans, m1+ m2);
            return max(m1, m2);
        }
    }
};

int main(){
    cout << "this is a good problem" << endl;
    vector<int> tree{-1, 0, 0, 0, 3};
    vector<int> tree2 {-1, 0, 0, 0, 2, 3, 5};
    Solution s;
    cout << s.solve(tree2) << endl;
}



