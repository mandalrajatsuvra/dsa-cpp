#include "iostream"
#include "unordered_map"
#include "queue"
#include "vector"
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
    Node* cloneTree(Node* root) {
        unordered_map<Node*, Node*> mp;
        queue<Node*> q;
        q.push(root);
        Node* clone = new Node(root->val);
        mp[root] = clone;
        while (!q.empty()){
            Node* node = q.front();
            q.pop();
            for(Node* neighbour: node->children){
                Node* clone_neighbour = new Node(neighbour->val);
                mp[neighbour] = clone_neighbour;
                mp[node]->children.push_back(clone_neighbour);
                q.push(neighbour);
            }
        }
        return mp[root];
    }
};