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
vector<vector<int>> res;
void fun(TreeNode *root, int sum, int targetSum, vector<int> path)
{
  if (root == nullptr)
  {
    return;
  }

  sum += (root->val);
  path.push_back(root->val);

  if (root->left == nullptr && root->right == nullptr)
  {
    // leaf node
    if (sum == targetSum)
    {
      res.push_back(path);

      return;
    }
    return;
  }

  else
  {
    // non leaf node
    // left jao
    fun(root->left, sum, targetSum, path);
    // right bhi jao
    fun(root->right, sum, targetSum, path);
    return;
  }
}
vector<vector<int>> pathSum(TreeNode *root, int targetSum)
{
  if (root == nullptr)
  {
    return {};
  }
  int sum = 0;
  vector<int> path;
  fun(root, sum, targetSum, path);
  return res;
}
};