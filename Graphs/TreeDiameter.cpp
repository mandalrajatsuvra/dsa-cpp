#include "iostream"
#include "vector"
#include "queue"
using namespace std;


class Solution {
public:
    int diameter;
    int treeDiameter(vector<vector<int>>& edges) {
        diameter = 0;
        int n = edges.size()+1;
        vector<int> tree[n];
        for(int i=0; i< edges.size(); i++){
            vector<int> edge = edges[i];
            int u = edge[0];
            int v = edge[1];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        vector<bool> visited(n, false);
        dfs(0, tree, visited);
        return diameter;
    }

    int dfs(int u, vector<int> tree[], vector<bool>& visited){
        visited[u] = true;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int v: tree[u]){
            if(!visited[v]){
                int t = 1+ dfs(v, tree, visited);
                if(minHeap.size() < 2){
                    minHeap.push(t);
                }else if(minHeap.top() < t){
                    minHeap.pop();
                    minHeap.push(t);
                }
            }
        }
        if(minHeap.size() == 0){
            return 0;
        }else if(minHeap.size() == 1){
            diameter = max(diameter, minHeap.top());
            int top = minHeap.top();
            minHeap.pop();
            return top;
        }else{
            int top1 = minHeap.top();
            minHeap.pop();
            int top2 = minHeap.top();
            minHeap.pop();
            diameter = max(diameter, top1+top2);
            return max(top1, top2);
        }
    }
};
int main(){

    Solution s;
    vector<vector<int>> vt{
            {0,1},{1,2},{2,3},{1,4},{4,5}
    };
    cout << s.treeDiameter(vt) << endl;

    vector<vector<int>> vt1{
            {0,1},{0,2}
    };
    cout << s.treeDiameter(vt1) << endl;
}

//Question: https://leetcode.com/problems/tree-diameter/description/