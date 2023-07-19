#include "iostream"
#include "vector"
#include "queue"
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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> levels;
        if(root == nullptr){
            return levels;
        }
        queue<Node*> queue;
        queue.push(root);
        while(!queue.empty()){
            int size = queue.size();
            vector<int> level;
            for(int i=0; i< size; i++){
                Node* node = queue.front();
                queue.pop();
                level.push_back(node->val);
                for(Node* child: node->children){
                    queue.push(child);
                }
            }
            levels.push_back(level);
        }
        return levels;
    }
};
