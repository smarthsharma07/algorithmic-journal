/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void dfs(TreeNode* root, string &ans){
        if (root == nullptr){
            ans+="N,";
            return;
        }
        ans+=to_string(root->val) + ",";
        dfs(root->left,ans);
        dfs(root->right,ans);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans ="";
        dfs(root,ans);
        return ans;
    }
    TreeNode* construct(stringstream &ss){
        string val;
        getline(ss, val, ',');
        if (val == "N")
            return nullptr;
        TreeNode* node = new TreeNode(stoi(val));
        node->left = construct(ss);
        node->right = construct(ss);
        return node;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return construct(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));