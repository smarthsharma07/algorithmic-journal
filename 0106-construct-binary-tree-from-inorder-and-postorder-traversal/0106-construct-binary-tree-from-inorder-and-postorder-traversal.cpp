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
    struct HashNode {
        int key;
        int value;
        HashNode* next;
        HashNode(int k, int v) : key(k), value(v), next(nullptr) {}
    };
    static const int TABLE_SIZE = 10007; // Prime number for hash table
    HashNode* hashTable[TABLE_SIZE] = {nullptr};
    int hash(int key) {
        int h = key % TABLE_SIZE;
        if (h < 0) h += TABLE_SIZE;
        return h;
    }
    void insert(int key, int value) {
        int index = hash(key);
        HashNode* node = new HashNode(key, value);
        node->next = hashTable[index];
        hashTable[index] = node;
    }
    int get(int key) {
        int index = hash(key);
        HashNode* curr = hashTable[index];
        while (curr) {
            if (curr->key == key) return curr->value;
            curr = curr->next;
        }
        return -1;
    }
    TreeNode* build(vector<int>& inorder, int inStart, int inEnd,
                    vector<int>& postorder, int postStart, int postEnd) {
        if (inStart > inEnd || postStart > postEnd) return nullptr;
        int rootVal = postorder[postEnd];
        TreeNode* root = new TreeNode(rootVal);
        int inRoot = get(rootVal);
        int leftSize = inRoot - inStart;
        root->left = build(inorder, inStart, inRoot - 1,
                           postorder, postStart, postStart + leftSize - 1);
        root->right = build(inorder, inRoot + 1, inEnd,
                            postorder, postStart + leftSize, postEnd - 1);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for (int i = 0; i < n; ++i) {
            insert(inorder[i], i);
        }
        return build(inorder, 0, n - 1, postorder, 0, n - 1);
    }
};