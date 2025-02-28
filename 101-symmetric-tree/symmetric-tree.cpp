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
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        vector<int>res1;
        vector<int>res2;
        left(root->left,res1);
        right(root->right,res2);
        // for(int i=0;i<res1.size();i++){
        //     if(res1[i]==res2[i]){
        //         return 1;

        //     }
        // }
        return res1==res2;
    }
    public:
    void left(TreeNode* root,vector<int> &res1){
        if(root == NULL){
            res1.push_back(-101);
            return;
        }

        res1.push_back(root->val);
        left(root->left,res1);
        left(root->right,res1);
        
    }
    void right(TreeNode* root,vector<int> &res2){
        if (!root) {
            res2.push_back(-101); 
            return;
        }

        res2.push_back(root->val);
        right(root->right,res2);
        right(root->left,res2);
        
    }
};