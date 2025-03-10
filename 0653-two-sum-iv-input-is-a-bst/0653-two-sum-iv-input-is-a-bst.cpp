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
    void inorder(TreeNode* root, vector<int> &res){
        if(root != nullptr){
            inorder(root->left, res);
            res.push_back(root->val);
            inorder(root->right, res);
        }
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int > res;
        inorder(root,res);
        int l=0;
        int r=res.size()-1;
        while(l < r){
            int sum=res[r]+res[l];
            if(sum == k) return 1;
            if(sum<k) l++;
            else r--;
        }
        return 0;

        
    }
};