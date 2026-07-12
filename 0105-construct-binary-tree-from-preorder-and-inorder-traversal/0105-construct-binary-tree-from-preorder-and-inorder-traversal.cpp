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
    unordered_map<int,int>mpp;
    int pre  = 0;
    TreeNode* build(vector<int>& preorder, int l , int r){
        if (l>r){
            return nullptr;
        }
        int rootval = preorder[pre++];
        TreeNode* root = new TreeNode(rootval);
        int mid = mpp[rootval];
        root->left = build(preorder, l, mid - 1);
        root->right = build(preorder, mid + 1, r);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0;i<inorder.size();i++){
            mpp[inorder[i]] = i;
        }
        return build(preorder,0,inorder.size()-1);
    }
};