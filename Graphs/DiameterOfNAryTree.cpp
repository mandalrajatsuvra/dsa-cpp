#include "iostream"
#include "vector"
#include "unordered_set"
#include "queue"
#include "unordered_map"
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;
    Node() {}
    Node(int _val) {
        val = _val;
    }
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
class Solution {
public:
    int diameter(Node* root) {
        unordered_map<Node*, Node*> mp;
        dfs(root, nullptr, mp);
        pair<Node*, int> e_node = bfs(root, mp);
        return bfs(e_node.first, mp).second;
    }
    pair<Node*, int> bfs(Node* root, unordered_map<Node*, Node*>& mp){
        unordered_set<Node*> visited;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        visited.insert(root);
        int distance = -1;
        Node* res = nullptr;
        while(!q.empty()){
            pair<Node *, int> node = q.front();
            q.pop();
            int dist = node.second;
            Node* u = node.first;
            if(dist > distance){
                distance = dist;
                res = u;
            }
            for(Node* v: u->children){
                if(visited.find(v) == visited.end()){
                    visited.insert(v);
                    q.push({v, dist+1});
                }
            }
            Node* p = mp[u];
            if(p!= nullptr && visited.find(p) == visited.end()){
                visited.insert(p);
                q.push({p, dist+1});
            }
        }
        return {res, distance};
    }
    void dfs(Node* root, Node* parent, unordered_map<Node*, Node*>& mp){
        if(root == nullptr){
            return;
        }
        mp[root] = parent;
        for(Node* node: root->children){
            dfs(node, root, mp);
        }
    }
};
//Question: https://leetcode.com/problems/diameter-of-n-ary-tree/description/