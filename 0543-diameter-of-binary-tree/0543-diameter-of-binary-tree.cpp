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
    int maxdiam=0;
    int getheight(TreeNode* node){
        if (node==nullptr){
            return 0;
        }
        int lh = getheight(node->left);
        int rh = getheight(node->right);
        maxdiam=max(maxdiam,lh+rh);
        return max(lh,rh)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        getheight(root);
        return maxdiam;
    }
};