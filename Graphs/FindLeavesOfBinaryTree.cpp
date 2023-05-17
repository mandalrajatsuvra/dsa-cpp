#include "iostream"
#include "vector"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        while(true){
            vector<int> vec;
            if(root->left == nullptr && root->right == nullptr){
                vec.push_back(root->val);
                res.push_back(vec);
                break;
            }
            root = dfs(root, vec);
            res.push_back(vec);
        }
        return res;
    }
    TreeNode* dfs(TreeNode* root, vector<int>& leaves){
        if(root== nullptr){
            return nullptr;
        }
        if(root->left == nullptr && root->right == nullptr){
            leaves.push_back(root->val);
            return nullptr;
        }
        root->left = dfs(root->left, leaves);
        root->right = dfs(root->right, leaves);
        return root;
    }
};


//Question: https://leetcode.com/problems/find-leaves-of-binary-tree/description/