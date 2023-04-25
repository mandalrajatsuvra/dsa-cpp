/*Problem Description

Given a binary search tree A, where each node contains a positive integer, and an integer B, you have to find whether or not there exist two different nodes X and Y such that X.value + Y.value = B.

        Return 1 to denote that two such nodes exist. Return 0, otherwise.



Problem Constraints
1 <= size of tree <= 100000

1 <= B <= 109



Input Format
First argument is the head of the tree A.

Second argument is the integer B.
Output Format
Return 1 if such a pair can be found, 0 otherwise.


Example Input
Input 1:

10
/ \
        9   20

B = 19

Input 2:

10
/ \
        9   20

B = 40

Example Output
Output 1:

1
Output 2:

0

Example Explanation
Explanation 1:

10 + 9 = 19. Hence 1 is returned.
Explanation 2:

No such pair exists.*/


#include "iostream"
#include "vector"
#include "unordered_map"
#include "unordered_set"

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool solve(TreeNode* root, int sum, unordered_set<int>& st){
    if(root == nullptr){
        return sum == 0;
    }
    bool left =  solve(root->left, sum, st);
    if(left == true){
        return true;
    }
    if(st.find(sum - root->val) != st.end()){
        return true;
    }
    st.insert(root->val);
    return solve(root->right, sum, st);
}

int t2sum(TreeNode* root, int sum){
    unordered_set<int> st;
    return solve(root, sum, st)? 1: 0;
}
int main(){
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    cout << t2sum(root, 18) << endl;
}
