/*
Chhota Bheem wants to eat the maximum number of ladoos in Dholakpur on Independence Day. The houses in Dholakpur are arranged in the form of a binary tree and have ladoos the same as their house number. Chhota Bheem is standing at his home initially.
Find the maximum ladoos he can eat if he can go to houses within a maximum distance k from his house. The number of ladoos at his home should also be included in the sum.

Note: Every house has distinct ladoos in it.
Example 1:

Input:
1
/    \
                2      9
/      /  \
              4      5     7
/   \         /  \
           8     19     20    11
/     /  \
         30   40   50
home = 9, K = 1
Output:
22
Explanation:
Initially Bheem at 9, so sum = 9
In 2nd move he went to 5, sum=9+5=14
In 3rd move he went to 7, sum=14+7=21
In 4th move he went to 1, sum=21+1=22
So within K distance bheem can get 22 ladoos.
Example 2:

Input:


home = 40, K = 2
Output:
113
Explanation:
Initially Bheem at 40, so sum = 40
In 2nd move he went to 19, sum=40+19=59
In 3rd move he went to 4, sum=59+4=63
In 4th move he went to 50, sum=63+50=113
So within K distance bheem can get 113 ladoos.
*/

#include "iostream"
#include "unordered_map"
#include "queue"
#include "unordered_set"
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution{

public:
    Node* h_ptr = nullptr;
    int h_node = 0;
    int count(Node* root, int home, int k){
        h_node = home;
        unordered_map<Node*, Node*> mp;
        dfs(root, nullptr, mp);
        if(h_ptr == nullptr){
            return 0;
        }
        int totalCount = 0;
        queue<pair<Node*, int>> q;
        unordered_set<Node*> marked;
        q.push({h_ptr, 0});
        while(!q.empty()){
            pair<Node*, int>n = q.front();
            Node* node = n.first;
            int dist = n.second;
            totalCount += node->data;
            q.pop();
            if(dist < k) {
                if (node->left != nullptr && marked.find(node->left) == marked.end()) {
                    marked.insert(node->left);
                    q.push({node->left, dist+1});
                }
                if (node->right != nullptr && marked.find(node->right) == marked.end()) {
                    marked.insert(node->right);
                    q.push({node->right, dist+1});
                }
                Node *parent = mp[node];
                if (parent != nullptr && marked.find(parent) == marked.end()) {
                    marked.insert(parent);
                    q.push({parent, dist+1});
                }
            }

        }
        return totalCount;
    }
    void dfs(Node* root, Node* parent, unordered_map<Node*, Node*>& mp){
        if(root == nullptr){
            return;
        }
        if(root->data == h_node){
            h_ptr = root;
        }
        mp[root] = parent;
        dfs(root->left, root, mp);
        dfs(root->right, root, mp);
    }
};
int main(){




}





















