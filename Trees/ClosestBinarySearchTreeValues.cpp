#include "iostream"
#include "vector"
#include "queue"
#include "unordered_map"
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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        priority_queue<double> pq;
        unordered_map<double, int> mp;
        dfs(root, target, k, pq, mp);
        vector<int> res;
        for(auto& [_, value]: mp){
            res.push_back(value);
        }
        return res;
    }
    void dfs(TreeNode* root, double target, int k, priority_queue<double>& pq, unordered_map<double, int> & mp){
        if(root == nullptr){
            return;
        }
        double diff = static_cast<double >(root->val) - static_cast<double >(target);
        if(pq.size() < k){
            pq.push(diff);
            mp[diff] = root->val;
        }else if(diff < pq.top()){
            mp.erase(pq.top());
            pq.pop();
            pq.push(diff);
            mp[diff] = root->val;
        }
        dfs(root->left, target, k, pq, mp);
        dfs(root->right, target, k, pq, mp);
    }
};
