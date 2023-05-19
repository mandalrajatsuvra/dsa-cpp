#include "iostream"
#include "queue"

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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool is_level_complete = true;
        while (!q.empty()){
            int size = q.size();
            bool is_empty_left = false;
            for(int i=0; i< size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left != nullptr && node->right != nullptr){
                    if(is_empty_left){
                        return false;
                    }
                    if(!is_level_complete){
                        return false;
                    }
                    q.push(node->left);
                    q.push(node->right);
                }else if(node->left != nullptr){
                    if(is_empty_left){
                        return false;
                    }
                    if(!is_level_complete){
                        return false;
                    }
                    q.push(node->left);
                    is_empty_left = true;
                    is_level_complete= false;
                }else if(node->right != nullptr){
                    return false;
                }else{
                    is_empty_left = true;
                    is_level_complete = false;
                }
            }
        }
    }
};

int main(){

}