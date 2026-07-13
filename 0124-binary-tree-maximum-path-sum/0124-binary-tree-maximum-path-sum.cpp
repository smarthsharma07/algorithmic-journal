/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxsum = INT_MIN;
    int maxtree(TreeNode* node){
        if (node == nullptr){
            return 0;
        }
        int leftmaxtree = max(maxtree(node->left),0);
        int rightmaxtree = max(maxtree(node->right),0);
        int newpath = node->val + leftmaxtree + rightmaxtree;
        maxsum = max(maxsum,newpath);
        return node->val + max(leftmaxtree,rightmaxtree);
    }
    int maxPathSum(TreeNode* root) {
        maxtree(root);
        return maxsum;
    }
};