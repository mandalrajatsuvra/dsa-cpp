#include "iostream"
#include "vector"
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void kthSmallestHelper(TreeNode* root, vector<int>& v){
    if(root == nullptr){
        return;
    }
    kthSmallestHelper(root->left, v);
    v.push_back(root->val);
    kthSmallestHelper(root->right, v);
}
int kthSmallestElement(TreeNode* root, int k){
    vector<int> v;
    kthSmallestHelper(root, v);
    return v[k-1];
}
int main(){


}


