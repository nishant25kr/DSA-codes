class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            if ((p->val < root->val) && (q->val < root->val)) {
                root = root->left;  // Move to left subtree
            } 
            else if ((p->val > root->val) && (q->val > root->val)) {
                root = root->right; // Move to right subtree
            } 
            else {
                return root; // Found LCA
            }
        }
        return nullptr;
    }
};
