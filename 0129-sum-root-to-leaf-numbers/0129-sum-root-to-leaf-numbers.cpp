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
int totalSum = 0 ;
void fun(TreeNode* root , int num){
  if(root == nullptr){
    return ;
  }

  num = (num * 10 )+ root->val;

  if(root->left == nullptr && root->right == nullptr){
    totalSum += num;
    num = 0 ;
    return ;
  }
  else{
    fun(root->left , num);
    fun(root->right , num );
    return;
  }
}
int sumNumbers(TreeNode *root)
{
  if(root == nullptr){
    return 0;
  }

  int num = 0 ;
  fun(root , num);
  return totalSum;

}
};