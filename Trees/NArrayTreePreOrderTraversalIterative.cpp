#include "iostream"
#include "vector"
#include "stack"
#include "algorithm"
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
    vector<int> preorder(Node* root) {
        vector<int> res;
        if(root == nullptr){
            return res;
        }
        stack<Node*> stk;
        stk.push(root);
        while(!stk.empty()){
            Node* node = stk.top();
            stk.pop();
            res.push_back(node->val);
            vector<Node*> children = node->children;
            reverse(children.begin(), children.end());
            for(Node* child: children){
                if(child != nullptr) {
                    stk.push(child);
                }
            }
        }
        return res;
    }

};
