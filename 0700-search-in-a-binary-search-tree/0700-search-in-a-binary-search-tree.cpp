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
TreeNode *searchBST(TreeNode *root, int val)
{
  if (root == nullptr)
  {
    return nullptr;
  }
  if (root->val == val)
  {
    return root;
  }

  else if (root->val < val)
  {
    // val badi side par hai
    // matlab right side par hai
    return searchBST(root->right, val);
  }
  else
  {
    // val choti side par present hai
    return  searchBST(root->left, val);
  }
}
};