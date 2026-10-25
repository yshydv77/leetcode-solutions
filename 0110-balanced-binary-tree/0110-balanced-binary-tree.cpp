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
int maxDepth(TreeNode* root){
    if(root == nullptr){
        return 0;
    }

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return 1 + max(left , right);
}

bool isBalanced(TreeNode* root){
    if(root == nullptr){
        return true;
    }

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    if(abs(left -right ) > 1){
        return false;
    }

    // above code is only for 1 node we have to check for all the other left and right nodes of the biinary trree
    // so we have to move to the left and right nodes 
    bool lft = isBalanced(root->left);
    bool rght = isBalanced(root->right);

    return lft && rght;
}

};