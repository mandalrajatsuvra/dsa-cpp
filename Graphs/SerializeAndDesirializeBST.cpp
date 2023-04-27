#include "iostream"
#include "vector"
#include "string"
#include "sstream"
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    string serialize(TreeNode* root) {
        if(root == nullptr){
            return "";
        }
        string left =  serialize(root->left);
        string right = serialize(root->right);
        return to_string(root->val) + "-" + left + right;
    }
    TreeNode* deserialize(string data) {
        stringstream ss{data};
        string item;
        TreeNode* root = nullptr;
        while(getline(ss, item, '-')) {
            root = insert(root, stoi(item));
        }
        return root;
    }
    TreeNode* insert(TreeNode* root ,int node){
        if(root == nullptr){
            TreeNode* n = new TreeNode(node);
            return n;
        }
        if(root->val >= node){
            root->left = insert(root->left, node);
        }else{
            root->right = insert(root->right, node);
        }
        return root;
    }
};

int main(){
    Solution s;
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    string  s1 = s.serialize(root);
    s.deserialize(s1);

}



