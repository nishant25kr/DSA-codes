/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;

    void inOrder(TreeNode* root){
        if(!root) 
            return ;

        if(root->left != NULL)
            parent[root->left]=root;
        inOrder(root->left); 

        if(root->right != NULL)
            parent[root->right]=root;
        inOrder(root->right); 

    }

    void BFS(TreeNode* target, int k, vector<int> &res){
        queue<TreeNode*> q;
        q.push(target);

        unordered_set<int> visited;
        visited.insert(target->val);

        while(!q.empty()){
            int n=q.size();
            if(k==0)
                break;

            while(n--){
                TreeNode* node=q.front();
                q.pop();

                if(node->left != NULL && !visited.count(node->left->val)){
                    q.push(node->left);
                    visited.insert(node->left->val);
                }
                
                if(node->right != NULL && !visited.count(node->right->val)){
                    q.push(node->right);
                    visited.insert(node->right->val);
                }

                if(parent.count(node) && !visited.count(parent[node]->val)){
                    q.push(parent[node]);
                    visited.insert(parent[node]->val);
                }

            }
            k--;
        }
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            res.push_back(temp->val);
        }

    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>res;
        inOrder(root);
        BFS(target, k, res);
        return res;

        
    }
};