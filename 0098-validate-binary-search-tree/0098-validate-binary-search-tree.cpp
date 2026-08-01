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
    bool ans = true ;
    TreeNode* prev = nullptr;
    void fun(TreeNode* root ){
        if(root == nullptr){
            return ;
        }

        fun(root->left );

        if(prev == nullptr){
            prev = root;
        }
        else {
            if(prev->val >= root->val){
                ans = false;
            }
            prev = root;
        }

        fun(root->right);

    }
    bool isValidBST(TreeNode* root) {
        if(root == nullptr || (root->left == nullptr && root->right == nullptr)){
            return true;
        }

        fun(root);
        return ans;
    }
};