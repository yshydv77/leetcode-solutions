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
bool ans = true;
int height(TreeNode* node){
  if(node == nullptr){
    return 0;
  }
  if(node->left == nullptr && node->right == nullptr){
    return 1;
  }

  int left = height(node->left);
  int right =  height(node->right);
    if(abs(left-right) > 1){
        ans = false;
    }
  return 1 + max( left,right);
}
bool isBalanced(TreeNode *root)
{
  if(root == nullptr){
    return true;
  }

  if(root->left == nullptr && root->right == nullptr){
    return true;
  }

    int a = height(root);

  return ans;

}
};