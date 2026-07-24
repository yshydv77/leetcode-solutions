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
vector<int> rightSideView(TreeNode *root)
{
  if(root == nullptr){
    return {};
  }
  if(root->left == nullptr && root->right == nullptr){
    return {root->val};
  }
  vector<int>ans;
  queue<TreeNode*>q;
  q.push(root);

  while (!q.empty())
  {
    int siz = q.size();
    while(siz--){
      TreeNode* t = q.front();
      q.pop();
      if(siz == 0){
        ans.push_back(t->val);
      }

      if(t->left != nullptr){
        q.push(t->left);
      }
      if(t->right != nullptr){
        q.push(t->right);
      }
    }
  }

  return ans;
  
}
};