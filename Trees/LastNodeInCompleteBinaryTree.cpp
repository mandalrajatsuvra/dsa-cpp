#include "iostream"
#include "queue"
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int lastNodeInCompleteBinaryTree(TreeNode* root){
    int res = -1;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        for(int i=0; i< size; i++){
            TreeNode* node = q.front();
            level.push_back(node->val);
            q.pop();
            if(node->left != nullptr){
                q.push(node->left);
            }
            if(node->right != nullptr){
                q.push(node->right);
            }
        }
        res = level[level.size()-1];
    }
    return res;
}
int main(){
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(11);
    root->right = new TreeNode(12);
    root->right->left = new TreeNode(14);
    cout << lastNodeInCompleteBinaryTree(root) << endl;
}




