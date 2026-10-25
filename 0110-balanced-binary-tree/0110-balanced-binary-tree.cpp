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
int Height(TreeNode* root){
    if(root == nullptr) return 0;

    int left = Height(root ->left);
    int right = Height(root->right);
    if(left == -1 || right == -1) return -1;
    if(abs(left-right) > 1 ) return -1;
    return 1 + max(left,right );

}
bool isBalanced(TreeNode* root){
    // logic : if the ans == -1 then the tree is not balanced 
    // otherwise then the tree will going to return the valid height of tree so return true
    int ans = Height(root);
    if(ans == -1) return false;
    return true;
}

};