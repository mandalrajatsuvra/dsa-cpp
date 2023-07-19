#include "iostream"
#include "vector"

using namespace std;

// Incomplete

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
    int rob(TreeNode* root) {
        return f(root, 0, false).first;
    }
    pair<int, bool> f(TreeNode* root, int sum,  bool selected){
        if(root == nullptr){
            return {0, false};
        }
        if(!selected){
            pair<int, bool> left = max(f(root->left, sum + root->val, true),
                   f(root->left, sum, false));
            pair<int, bool> right = max(f(root->right, sum + root->val, true),
                            f(root->right,sum, false));
            if(!left.second && !right.second){
                return {left.first + right.first + root->val, true};
            }else{
                return {left.first + right.first , false};
            }
        }else{
            pair<int, bool> left =  f(root->left, sum, false);
            pair<int, bool> right = f(root->right,sum, false);
            if(!left.second && !right.second){
                return {left.first + right.first + root->val, true};
            }else{
                return {left.first + right.first , false};
            }
        }
    }
};

int main(){


}
