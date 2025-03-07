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
    void findkth(TreeNode* root, vector<int> &res){
        if(root==NULL) return ;

        res.push_back(root->val);
        findkth(root->left,res);
        findkth(root->right,res);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int > res;
        findkth(root,res);
        sort(res.begin(),res.end());
        return res[k-1];
        
    }
};