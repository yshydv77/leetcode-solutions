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
TreeNode* ans = nullptr;
int fun(TreeNode* root , TreeNode* p , TreeNode* q ){
  if(root == nullptr){
    return 0 ;
  }

  int left = fun(root->left , p , q );
  int right = fun(root->right , p , q);
  int self = 0 ;
  // self = 1 when the node can boss itself
  // matlab root node p and q ke barabar hai 

  if(root == p || root == q){
    self = 1;
  }
  int target = left + right + self;
  if(target == 2 && ans == nullptr){
    ans = root;
  }

  return target;
}
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
  
  int a = fun(root , p , q );
  return ans;
}
};